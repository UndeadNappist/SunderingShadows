// terminal_color_hex.c
// Takes a string, scans for hex codes, replaces them with their ANSI escapes
// Written by Spade on 8 Feb. 2023

string terminal_color_hex(string raw_string, mapping color_mapping, int screen_width)
{
    int i, width_remaining, temp_r, temp_g, temp_b, starting_point, last_available_space, next_newline, last_color, bold_enabled;
    string* exploded_argument;
    string temporary_string;
    mapping is_color_code;

    // Keeps track of whether or not a split was a color code.
    is_color_code = ([]);

    // Split the string up into color escapes, add a backslash at the end to prevent the last split (potentially non-escaped) from always being counted as a color.
    exploded_argument = explode(raw_string, "%^");

    for (i = 0; i < sizeof(exploded_argument); ++i)
    {
        // If the first real characters in this string aren't %^ and this is the first split, disregard.
         if (i == 0 && raw_string[0..1] != "%^" )
            continue;

        // If the last real characters in this string aren't %^ and this is the first split, disregard.
        temporary_string = rtrim(raw_string);

        if (i == sizeof(exploded_argument) - 1 && temporary_string[<2..<1] != "%^" )
            continue;

        // If the argument matches an entry in the mapping
        if (color_mapping[exploded_argument[i]])
        {
            is_color_code[i] = 1;
            exploded_argument[i] = color_mapping[exploded_argument[i]];
            continue;
        }

        // If the first character of this fragment isn't a #, check if it has a key in the map.
        if (exploded_argument[i][0] != '#')
            continue;

        // If the code isn't seven characters long, disregard.
        if (sizeof(exploded_argument[i]) != 7)
            continue;

        // If the Red value is malformed, disregard.
        if (!sscanf(exploded_argument[i][1..2], "%x", temp_r))
            continue;

        // If the Green value is malformed, disregard.
        if (!sscanf(exploded_argument[i][3..4], "%x", temp_g))
            continue;

        // If the Blue value is malformed, disregard.
        if (!sscanf(exploded_argument[i][5..6], "%x", temp_b))
            continue;

        // Mark this fragment as a color code.
        is_color_code[i] = 1;

        // Replace the current fragment with its respective color code
        exploded_argument[i] = "\033[38;2;" + temp_r + ";" + temp_g + ";" + temp_b + "m";
    }

    // If we have don't a screen width...
    if (!screen_width)
    {
        return implode(exploded_argument, "");
    }

    // Wrap the string.
    width_remaining = screen_width;
    last_color = -1;

    for (i = 0; i < sizeof(exploded_argument); ++i)
    {
        // Set our initial conditions
        temporary_string = "";
        starting_point = 0;

        // If this segment is a color track it and skip it.
        if (is_color_code[i])
        {
            last_color = i;

            if (exploded_argument[i] == "BOLD")    // Whoever decided that we use *bold* to access bright colors... I hate you.
                bold_enabled = 1;
            else if (exploded_argument[i] == "RESET")
                bold_enabled = 0;

            continue;
        }

        // Add all of the text that can be nicely fit.
        while (1)
        {
            if (sizeof(exploded_argument[i]) <= starting_point)
                break;

            // Find our next available points of interest.
            last_available_space = strsrch(exploded_argument[i][starting_point..starting_point + width_remaining], " ", -1);
            next_newline = strsrch(exploded_argument[i][starting_point..starting_point + width_remaining], "\n");

            // If we found a newline
            if (next_newline != -1)
            {
                temporary_string += exploded_argument[i][starting_point..starting_point + next_newline];
                if (last_color != -1)
                {
                    if (bold_enabled)
                        temporary_string += color_mapping["BOLD"];

                    temporary_string += exploded_argument[last_color];
                }

                width_remaining = screen_width;
                starting_point += next_newline + 1;
                continue;
            }

            // If there is a space within our remaining width, and the next word isn't longer than our screen width.
            if (last_available_space != -1)
            {
                // If this is not the last space in the segment or this space fits exactly
                if (strsrch(exploded_argument[i][starting_point + last_available_space + 1..<1], " ") != -1 || sizeof(exploded_argument[i][starting_point..starting_point + last_available_space - 1]) == width_remaining)
                {
                    exploded_argument[i][starting_point + last_available_space] = 10;
                    if (last_color != -1)
                    {
                        if (bold_enabled)
                            temporary_string += color_mapping["BOLD"];

                        temporary_string += exploded_argument[last_color];
                    }

                    width_remaining = screen_width;
                }
                else
                {
                    width_remaining -= sizeof(exploded_argument[i][starting_point..starting_point + last_available_space]);
                }
                temporary_string += exploded_argument[i][starting_point..starting_point + last_available_space];

                starting_point += last_available_space + 1;

                continue;
            }

            // If we can fit the rest of the segment in with surplus space, do it.
            if (sizeof(exploded_argument[i][starting_point..<1]) < width_remaining)
            {
                temporary_string += exploded_argument[i][starting_point..<1];
                width_remaining -= sizeof(exploded_argument[i][starting_point..<1]);
                break;
            }

            // If we can fit the rest of the segment in perfectly, do it.
            if (sizeof(exploded_argument[i][starting_point..<1]) == width_remaining)
            {
                temporary_string += exploded_argument[i][starting_point..<1] + "\n";
                if (last_color != -1)
                {
                    if (bold_enabled)
                        temporary_string += color_mapping["BOLD"];

                    temporary_string += exploded_argument[last_color];
                }

                width_remaining = screen_width;
                break;
            }

            // If we can't fit the whole rest of the segment in, split it.
            temporary_string += exploded_argument[i][starting_point..starting_point + width_remaining - 1] + "\n";
            if (last_color != -1)
            {
                if (bold_enabled)
                    temporary_string += color_mapping["BOLD"];

                temporary_string += exploded_argument[last_color];
            }

            starting_point += width_remaining;
            width_remaining = screen_width;
        }

        exploded_argument[i] = temporary_string;
    }

    // Join the exploded fragments as a string and return.
    return replace_string(implode(exploded_argument, ""), " \n", "\n");
}

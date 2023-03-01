// terminal_color_hex.c
// Takes a string, scans for hex codes, replaces them with their ANSI escapes
// Written by Spade on 8 Feb. 2023

string terminal_color_hex(string raw_string, mapping color_mapping, int screen_width)
{
    int i, j, width_remaining, temp_r, temp_g, temp_b, last_space_fragment, last_space_position, characters_since_last_space, bold_enabled;
    string* exploded_argument;
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
        if (i == sizeof(exploded_argument) - 1 && rtrim(raw_string)[<2..<1] != "%^" )
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

        // Replace the current fragment with its respective color code if the terminal is FANSI (hehe)
        if (color_mapping[1] == 1)
            exploded_argument[i] = "\033[38;2;" + temp_r + ";" + temp_g + ";" + temp_b + "m";
        else
            exploded_argument[i] = "";
    }

    // If we have don't a screen width...
    if (!screen_width)
    {
        return implode(exploded_argument, "");
    }

    // Wrap the string.
    width_remaining = screen_width;
    last_space_position = -1;

    for (i = 0; i < sizeof(exploded_argument); ++i)
    {
        // If this segment is a color, skip it.
        if (is_color_code[i])
            continue;

        for (j = 0; j < sizeof(exploded_argument[i]); ++j)
        {
            if (exploded_argument[i][j] == 10)
            {
                width_remaining = screen_width;
                continue;
            }

            if (width_remaining < 1)
            {
                if (exploded_argument[i][j] == ' ')
                {
                    exploded_argument[i][j] = 10;    // Make this a helper function for fuck's sake
                    last_space_position = -1;
                    width_remaining = screen_width;
                    continue;
                }

                if (screen_width < characters_since_last_space || last_space_position == -1)
                {
                    exploded_argument[i] = exploded_argument[i][0..j - 1] + "\n" + exploded_argument[i][j..<1];    // Make this a helper function for fuck's sake
                    last_space_position = -1;
                    width_remaining = screen_width;
                    continue;
                }

                exploded_argument[last_space_fragment][last_space_position] = 10;    // Make this a helper function for fuck's sake
                i = last_space_fragment;
                j = last_space_position;
                last_space_position = -1;
                width_remaining = screen_width;
                continue;
            }

            if (exploded_argument[i][j] == ' ')
            {
                last_space_fragment = i;
                last_space_position = j;
                characters_since_last_space = 0;
                --width_remaining;
                continue;
            }

            --width_remaining;
            ++characters_since_last_space;
        }
    }

    // Join the exploded fragments as a string and return.
    return implode(exploded_argument, "");
}

// terminal_color_hex.c
// Takes a string, scans for hex codes, replaces them with their ANSI escapes
// Written by Spade on 8 Feb. 2023

string terminal_color_hex(string raw_string, mapping terminal_information, int x)
{
    int i, temp_r, temp_g, temp_b;
    string* exploded_argument;
    string colored_string, temp_color_string;

    // Split the string up into color escales, add a backslash at the end to prevent the last split (potentially non-escaped) from always being counted as a color.
    exploded_argument = explode(raw_string + " ", "%^");

    for (i = 0; i < sizeof(exploded_argument); ++i)
    {
        // If the first character of this fragment isn't a #, disregard.
        if (exploded_argument[i][0] != '#')
            continue;

        // If the code isn't seven characters long, disregard.
        if (sizeof(exploded_argument[i]) != 7)
            continue;

        // If the appended space is present on the last split, disregard.
        if (i == sizeof(exploded_argument) - 1 && exploded_argument[i][sizeof(exploded_argument[i]) - 1] == ' ')
            continue;

        // Avoid some bullshit with character concatenation
        temp_color_string = "00";

        // If the Red value is malformed, disregard.
        temp_color_string[0] = exploded_argument[i][1];
        temp_color_string[1] = exploded_argument[i][2];

        if (!sscanf(temp_color_string, "%x", temp_r))
            continue;

        // If the Green value is malformed, disregard.
        temp_color_string[0] = exploded_argument[i][3];
        temp_color_string[1] = exploded_argument[i][4];

        if (!sscanf(temp_color_string, "%x", temp_g))
            continue;

        // If the BLue value is malformed, disregard.
        temp_color_string[0] = exploded_argument[i][5];
        temp_color_string[1] = exploded_argument[i][6];

        if (!sscanf(temp_color_string, "%x", temp_b))
            continue;

        exploded_argument[i] = "\033[38;2;" + temp_r + ";" + temp_g + ";" + temp_b + "m";
    }

    // We are messy here because we add extranious color escapes, but that's okay because the terminal_colour efun will clean it up for us.
    colored_string = rtrim(implode(exploded_argument, "%^"));

    return terminal_colour(colored_string, terminal_information, x, 0);
}

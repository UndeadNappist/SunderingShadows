/**
 * @file
 */

/**
 * Rolls a NdM dice
 *
 * @param num N
 * @param sides M
 * @reutn Sum of the roll
 */

// Tlaloc added advantage/disadvantage modifier 9.18.21
// Shifted to take the maximum of each die, as opposed to the maximum of each pool - Spade, 23 March 2023

// Rolling and rolling with advantage might benefit from being different sefuns alltogether // Spade

int roll_dice(int num, int sides, int adv)
{
    int i, roll, roll2, aggregator;

    aggregator = 0;


    if (adv != 0)
    {
        for (i = 0; i < num; ++ i)
        {
            roll  = random(sides) + 1;
            roll2 = random(sides) + 1;

            if (adv < 0)
                aggregator += roll < roll2 ? roll : roll2;
            else
                aggregator += roll < roll2 ? roll2 : roll;
        }

        return aggregator;
    }

    for (i = 0; i < num; ++i)
        aggregator += random(sides) + 1;

    return aggregator;

}

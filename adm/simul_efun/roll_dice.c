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
 
//Tlaloc added advantage/disadvantage modifier 9.18.21
//Updated to add flat amount as advantage on rolls (20% of max)
 
int roll_dice(int num, int sides, int adv)
{
    int x, cnt;

    cnt = 0;
        
    for (x = 0; x < num; x++)
        cnt += random(sides) + 1;
    
    if(adv != 0)
    {
        int max, mod;
        
        max = num * sides;
        mod = adv * ((max * 20) / 100);
        cnt += mod;
        cnt = cnt > max ? max : cnt;
        cnt = cnt < num ? num : cnt;
    }     
        
    return cnt;
}
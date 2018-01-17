if(grid.at(r).at(c) == EMPTY)
            {
                if(grid.at(r).at(c + 1) == COLOR)
                {
                    grid.at(r).at(c) = TO_BE_COLORED;
                }
                else if(grid.at(r).at(c - 1) == COLOR)
                {
                    grid.at(r).at(c) = TO_BE_COLORED;
                }
                else if(grid.at(r + 1).at(c) == COLOR)
                {
                    grid.at(r).at(c) = TO_BE_COLORED;
                }
                else if(grid.at(r - 1).at(c) == COLOR)
                {
                    grid.at(r).at(c) = TO_BE_COLORED;
                }
            }
            
if(grid.at(r).at(c) == EMPTY)
{
if(grid.at(r).at(c + 1) == COLOR)
{
grid.at(r).at(c) = TO_BE_COLORED;
}
else if(grid.at(r).at(c - 1) == COLOR)
{
grid.at(r).at(c) = TO_BE_COLORED;
}
else if(grid.at(r + 1).at(c) == COLOR)
{
grid.at(r).at(c) = TO_BE_COLORED;
}
else if(grid.at(r - 1).at(c) == COLOR)
{
grid.at(r).at(c) = TO_BE_COLORED;
}
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
xSS                           x
xxxxxxxxxxxxxxxxxxxx xxxxxxxxxx
x                 xx          x
xxxxxxxxx xxxxxxx xxxxxxx xxxxx
x               x             x
xxxxx xxxxxxxxxxx xxxxxxxxxxxxx
x                             x
xxxxxxxxxxxxxxxxxxxxxxxxxxGGxxx

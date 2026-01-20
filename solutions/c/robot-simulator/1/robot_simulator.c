#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t new_status;

    new_status.direction = direction;
    new_status.position.x = x;
    new_status.position.y = y;

    return new_status;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    int i = 0;
    while(commands[i] != '\0')
    {
        if(commands[i] == 'L' && robot->direction == DIRECTION_NORTH) robot->direction = DIRECTION_WEST;
        else if(commands[i] == 'L') robot->direction --;
        else if(commands[i] == 'R' && robot->direction == DIRECTION_WEST) robot->direction = DIRECTION_NORTH;
        else if(commands[i] == 'R') robot->direction++;       
        else if(commands[i] == 'A')
        {
            //I need to check the currecnt direction and need to make a step forward in this direction
            switch (robot->direction)
            {
            case DIRECTION_NORTH:
                robot->position.y++;
                break;
            case DIRECTION_EAST:
                robot->position.x++;
                break;
            case DIRECTION_SOUTH:
                robot->position.y--;
                break;
            case DIRECTION_WEST:
                robot->position.x--;
                break;               
            default:
                break;
            }
        }
        i++;
    }
}
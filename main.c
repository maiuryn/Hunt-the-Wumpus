#include <stdio.h>
#include <stdlib.h> // for srand
#include <string.h> // for string functions

//--------------------------------------------------------------------------------
void displayCave() {
  printf("\n"
         "       ______18______             \n"
         "      /      |       \\           \n"
         "     /      _9__      \\          \n"
         "    /      /    \\      \\        \n"
         "   /      /      \\      \\       \n"
         "  17     8        10     19       \n"
         "  | \\   / \\      /  \\   / |    \n"
         "  |  \\ /   \\    /    \\ /  |    \n"
         "  |   7     1---2     11  |       \n"
         "  |   |    /     \\    |   |      \n"
         "  |   6----5     3---12   |       \n"
         "  |   |     \\   /     |   |      \n"
         "  |   \\       4      /    |      \n"
         "  |    \\      |     /     |      \n"
         "  \\     15---14---13     /       \n"
         "   \\   /            \\   /       \n"
         "    \\ /              \\ /        \n"
         "    16---------------20           \n"
         "\n");
}

//--------------------------------------------------------------------------------
void displayInstructions() {
  printf("Hunt the Wumpus:                                             \n"
         "The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
         "room has 3 tunnels leading to other rooms.                   \n"
         "                                                             \n"
         "Hazards:                                                     \n"
         "1. Two rooms have bottomless pits in them.  If you go there you fall "
         "and die.   \n"
         "2. Two other rooms have super-bats.  If you go there, the bats grab "
         "you and     \n"
         "   fly you to some random room, which could be troublesome.  Then "
         "those bats go \n"
         "   to a new room different from where they came from and from the "
         "other bats.   \n"
         "3. The Wumpus is not bothered by the pits or bats, as he has sucker "
         "feet and    \n"
         "   is too heavy for bats to lift.  Usually he is asleep.  Two things "
         "wake       \n"
         "    him up: Anytime you shoot an arrow, or you entering his room.  "
         "The Wumpus   \n"
         "    will move into the lowest-numbered adjacent room anytime you "
         "shoot an arrow.\n"
         "    When you move into the Wumpus' room, then he wakes and moves if "
         "he is in an \n"
         "    odd-numbered room, but stays still otherwise.  After that, if he "
         "is in your \n"
         "    room, he snaps your neck and you die!                            "
         "           \n"
         "                                                                     "
         "           \n"
         "Moves:                                                               "
         "           \n"
         "On each move you can do the following, where input can be upper or "
         "lower-case:  \n"
         "1. Move into an adjacent room.  To move enter 'M' followed by a "
         "space and       \n"
         "   then a room number.                                               "
         "           \n"
         "2. Shoot your guided arrow through a list of up to three adjacent "
         "rooms, which  \n"
         "   you specify.  Your arrow ends up in the final room.               "
         "           \n"
         "   To shoot enter 'S' followed by the number of rooms (1..3), and "
         "then the      \n"
         "   list of the desired number (up to 3) of adjacent room numbers, "
         "separated     \n"
         "   by spaces. If an arrow can't go a direction because there is no "
         "connecting   \n"
         "   tunnel, it ricochets and moves to the lowest-numbered adjacent "
         "room and      \n"
         "   continues doing this until it has traveled the designated number "
         "of rooms.   \n"
         "   If the arrow hits the Wumpus, you win! If the arrow hits you, you "
         "lose. You  \n"
         "   automatically pick up the arrow if you go through a room with the "
         "arrow in   \n"
         "   it.                                                               "
         "           \n"
         "3. Enter 'R' to reset the person and hazard locations, useful for "
         "testing.      \n"
         "4. Enter 'C' to cheat and display current board positions.           "
         "           \n"
         "5. Enter 'D' to display this set of instructions.                    "
         "           \n"
         "6. Enter 'P' to print the maze room layout.                          "
         "           \n"
         "7. Enter 'X' to exit the game.                                       "
         "           \n"
         "                                                                     "
         "           \n"
         "Good luck!                                                           "
         "           \n"
         " \n\n");
} // end displayInstructions()

// reRanzomize will randomize the value so that its not the same as the other
// values
void reRandomize(int choice, int *p, int *w, int *p1, int *p2, int *b1, int *b2,
                 int *a) {
  switch (choice) {
    // for the player room
  case 0:
    while ((*a == *p) || (*w == *p) || (*p1 == *p) || (*p2 == *p) ||
           (*b1 == *p) || (*b2 == *p) || !(*a > 0)) {
      *p = rand() % 20 + 1;
    }
    break;

  case 1:
    // for the wumpus
    while ((*p == *w) || (*w == *a) || (*p1 == *w) || (*p2 == *w) ||
           (*b1 == *w) || (*b2 == *w) || !(*w > 0)) {
      *w = rand() % 20 + 1;
    }

  case 2:
    // for the first pit
    while ((*p == *p1) || (*w == *p1) || (*p1 == *a) || (*p2 == *p1) ||
           (*b1 == *p1) || (*b2 == *p1) || !(*p1 > 0)) {
      *p1 = rand() % 20 + 1;
    }
    break;

  case 3:
    // for the second pit
    while ((*p == *p2) || (*w == *p2) || (*p1 == *p2) || (*p2 == *a) ||
           (*b1 == *p2) || (*b2 == *p2) || !(*p2 > 0)) {
      *p2 = rand() % 20 + 1;
    }
    break;
  case 4:
    // for the first bat
    while ((*p == *b1) || (*w == *b1) || (*p1 == *b1) || (*p2 == *b1) ||
           (*b1 == *a) || (*b2 == *b1) || !(*b1 > 0)) {
      *b1 = rand() % 20 + 1;
    }
    break;
  case 5:
    // for the second bat
    while ((*p == *b2) || (*w == *b2) || (*p1 == *b2) || (*p2 == *b2) ||
           (*b1 == *b2) || (*b2 == *a) || !(*b2 > 0)) {
      *b2 = rand() % 20 + 1;
    }
    break;
  case 6:
    // for the arrow
    while ((*p == *a) || (*w == *a) || (*p1 == *a) || (*p2 == *a) ||
           (*b1 == *a) || (*b2 == *a) || !(*a > 0)) {
      *a = rand() % 20 + 1;
    }
    break;
  default:
    // Otherwise, the result is undefined
    break;
  }
}

// randGame() will randomize all the values inside the game in the following
// order:
/*
  1. person
  2. Wumpus
  3. pit1
  4. pit2
  5. bat1
  6. bat2
  7. arrow
*/
void randGame(int *p, int *w, int *p1, int *p2, int *b1, int *b2, int *a) {
  *p = rand() % 20 + 1;
  reRandomize(1, p, w, p1, p2, b1, b2, a); // randomize w
  reRandomize(2, p, w, p1, p2, b1, b2, a); // randomize p1
  reRandomize(3, p, w, p1, p2, b1, b2, a); // randomize p2
  reRandomize(4, p, w, p1, p2, b1, b2, a); // randomize b1
  reRandomize(5, p, w, p1, p2, b1, b2, a); // randomize b2
  reRandomize(6, p, w, p1, p2, b1, b2, a); // randomize a
  /*
  *w = rand() % 20 + 1;
  while (*w == *p) {
    *w = rand() % 20 + 1;
  }
  *p1 = rand() % 20 + 1;
  while (*w == *p1 || *p == *p1) {
    *p1 = rand() % 20 + 1;
  }
  *p2 = rand() % 20 + 1;
  while ((*p == *p2) || (*w == *p2) || (*p1 == *p2)) {
    *p2 = rand() % 20 + 1;
  }
  *b1 = rand() % 20 + 1;
  while ((*p == *b1) || (*w == *b1) || (*p1 == *b1) || (*p2 == *b1)) {
    *b1 = rand() % 20 + 1;
  }
  *b2 = rand() % 20 + 1;
  while ((*p == *b2) || (*w == *b2) || (*p1 == *b2) || (*p2 == *b2) ||
         (*b1 == *b2)) {
    *b2 = rand() % 20 + 1;
  }
  *a = rand() % 20 + 1;
  while ((*p == *a) || (*w == *a) || (*p1 == *a) || (*p2 == *a) ||
         (*b1 == *a) || (*b2 == *a)) {
    *a = rand() % 20 + 1;
  }*/
}

// setRooms manually sets up the map array
void setRooms(int **map) {
  // Room 1
  map[0][0] = 2;
  map[0][1] = 5;
  map[0][2] = 8;
  // Room 2
  map[1][0] = 1;
  map[1][1] = 3;
  map[1][2] = 10;
  // Room 3
  map[2][0] = 2;
  map[2][1] = 4;
  map[2][2] = 12;
  // Room 4
  map[3][0] = 3;
  map[3][1] = 5;
  map[3][2] = 14;
  // Room 5
  map[4][0] = 1;
  map[4][1] = 4;
  map[4][2] = 6;
  // Room 6
  map[5][0] = 5;
  map[5][1] = 7;
  map[5][2] = 15;
  // Room 7
  map[6][0] = 6;
  map[6][1] = 8;
  map[6][2] = 17;
  // Room 8
  map[7][0] = 1;
  map[7][1] = 7;
  map[7][2] = 9;
  // Room 9
  map[8][0] = 8;
  map[8][1] = 10;
  map[8][2] = 18;
  // Room 10
  map[9][0] = 2;
  map[9][1] = 9;
  map[9][2] = 11;
  // Room 11
  map[10][0] = 10;
  map[10][1] = 12;
  map[10][2] = 19;
  // Room 12
  map[11][0] = 3;
  map[11][1] = 11;
  map[11][2] = 13;
  // Room 13
  map[12][0] = 12;
  map[12][1] = 14;
  map[12][2] = 20;
  // Room 14
  map[13][0] = 4;
  map[13][1] = 13;
  map[13][2] = 15;
  // Room 15
  map[14][0] = 6;
  map[14][1] = 14;
  map[14][2] = 16;
  // Room 16
  map[15][0] = 15;
  map[15][1] = 17;
  map[15][2] = 20;
  // Room 17
  map[16][0] = 7;
  map[16][1] = 16;
  map[16][2] = 18;
  // Room 18
  map[17][0] = 9;
  map[17][1] = 17;
  map[17][2] = 19;
  // Room 19
  map[18][0] = 11;
  map[18][1] = 18;
  map[18][2] = 20;
  // Room 20
  map[19][0] = 13;
  map[19][1] = 16;
  map[19][2] = 19;
}

// Debug command shows rooms next to player
void debug(int pr, int **wumpusMap) {
  printf("\n%d\n", wumpusMap[pr - 1][0]); // print the lowest numbered room
  printf("%d\n", wumpusMap[pr - 1][1]);   // print the second lowest
  printf("%d", wumpusMap[pr - 1][2]);     // print the highest numbered room
}

// checkAdjacent will return 0 if lhs isn't a part of rhs in the map
// and will return 1 if rhs can be accessed from lhs
int checkAdjacent(int lhs, int rhs, int **wumpusMap) {
  return ((lhs == wumpusMap[rhs - 1][0]) || (lhs == wumpusMap[rhs - 1][1]) ||
          (lhs == wumpusMap[rhs - 1][2]));
}

//--------------------------------------------------------------------------------
int main(void) {
  // ----------------------------PREGAME SETUP----------------------------

  // wumpusMap is a 2D array of the entire map layout with all possible
  // movements from each index, 0 represents room number 1
  int **wumpusMap = malloc(20 * sizeof(int *)); // Initialize the array

  // Loop through each index and dynamically allocate space for it
  for (int i = 0; i < 20; i++) {
    wumpusMap[i] = (int *)malloc(3 * sizeof(int));
  }
  // Now set up the values in each room
  setRooms(wumpusMap);

  // srand(time(0));
  srand(1);

  // Initialize game values
  int moveNum = 1;

  int pit1 = -1;
  int pit2 = -1;
  int wumpus = -1;
  int playerRoom = -1;
  int bat1 = -1;
  int bat2 = -1;
  int arrow = -2; // arrow value of -1 means its with the person

  // Assign random game values
  randGame(&playerRoom, &wumpus, &pit1, &pit2, &bat1, &bat2, &arrow);

  // Allocate memory for the user's input
  char *userMove = calloc(20, sizeof(char));
  if (userMove == NULL) {
    printf("Not enough memory\n");
    return -1;
  }

  // While the user doesnt want to exit
  while (userMove[0] != 'x' || userMove[0] != 'X') {
    // --------PRINTING INFORMATION ABOUT ROOMS NEARBY---------------

    // If the room that the player is in has an arrow
    if (arrow == playerRoom) {
      // Player picks up arrow
      printf(
          "Congratulations, you found the arrow and can once again shoot.\n");
      arrow = -1;
    }

    // Tell about the room number
    printf("You are in room %d. ", playerRoom);

    // If wumpus is nearby
    if (checkAdjacent(wumpus, playerRoom, wumpusMap)) {
      printf("You smell a stench. ");
    }

    // If there's a pit nearby
    if (checkAdjacent(pit1, playerRoom, wumpusMap) ||
        checkAdjacent(pit2, playerRoom, wumpusMap)) {
      printf("You feel a draft. ");
    }

    // If there are bats nearby
    if (checkAdjacent(bat1, playerRoom, wumpusMap) ||
        checkAdjacent(bat2, playerRoom, wumpusMap)) {
      printf("You hear rustling of bat wings. ");
    }

    printf("\n");

    // ---------------GETTING USER INPUT-------------------

    // Tells the move number along with the prompt
    printf("\n%d. Enter your move (or 'D' for directions): ", moveNum);

    // Gets the input from the user and stores it into userMove
    scanf(" %s", userMove);

    // printf("%s", userMove);

    // --------------CHECKING PLAYER INPUT---------------

    // Cheating
    if (userMove[0] == 'C' || userMove[0] == 'c') {
      // Message for menu option C (cheating). Note that the printf() statement
      // below always prints 1, 2, 3, 4, 5, 6, 7
      printf("Cheating! Game elements are in the following rooms: \n"
             "Player Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n"
             "%4d %5d %6d %5d %5d %5d %5d \n\n",
             playerRoom, wumpus, pit1, pit2, bat1, bat2, arrow);

    }

    // Directions
    else if (userMove[0] == 'D' || userMove[0] == 'd') {
      displayCave();
      displayInstructions();

    }

    // Show the map
    else if (userMove[0] == 'P' || userMove[0] == 'p') {
      displayCave();

    }

    // Exit
    else if (userMove[0] == 'X' || userMove[0] == 'x') {
      break;

    }

    // Reset game values
    else if (userMove[0] == 'R' || userMove[0] == 'r') {
      // Prompt for user when they choose to reset
      printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, "
             "bats1, bats2, and arrow: \n\n");
      scanf(" %d %d %d %d %d %d %d", &playerRoom, &wumpus, &pit1, &pit2, &bat1,
            &bat2, &arrow);

    }

    // Guessing where wumpus is
    else if (userMove[0] == 'G' || userMove[0] == 'g') {
      // Prompt for guess of where Wumpus room is
      printf("Enter room (1..20) you think Wumpus is in: ");
      int guess = -1;       // Initialize a value for the player's guess
      scanf(" %d", &guess); // store the value typed into a variable

      // Both possible messages after the user guesses where the Wumpus is, for
      // a win or loss.
      // If the player guessed correctly
      if (guess == wumpus) {
        printf("You won!\n");
        break; // exit the loop to end the game

      }
      // Otherwise, the player loses
      else {
        printf("You lost.\n");
        break; // exit the loop to end the game
      }
    }

    // Moving the player
    else if ((userMove[0] == 'M' || userMove[0] == 'm')) {
      int roomChoice = -1;
      scanf(" %d", &roomChoice);

      // Check if the player can move to the adjacent room
      if (checkAdjacent(roomChoice, playerRoom, wumpusMap) &&
          (roomChoice > 0 && roomChoice < 21)) {
        moveNum++;
        playerRoom = roomChoice;

        if (playerRoom == wumpus) {
          // Both possible messages when the player enters a room that has the
          // Wumpus
          // Even numbered room
          if (playerRoom % 2 == 0) {
            printf("You briefly feel a slimy tentacled arm as your neck is "
                   "snapped. \n"
                   "It is over.\n");
            break;

          }
          // Odd numbered room
          else if (playerRoom % 2 == 1) {
            printf("You hear a slithering sound, as the Wumpus slips away. \n"
                   "Whew, that was close! \n");
            // Wumpus will move to the lowest-numbered adjacent room
            wumpus = wumpusMap[wumpus - 1][0];

          }
          // Undefined behavior
          else {
            continue;
          }
        }

        if (playerRoom == pit1 || playerRoom == pit2) {
          // Message when the player dies by falling into a pit
          printf("Aaaaaaaaahhhhhh....   \n");
          printf("    You fall into a pit and die. \n");
          break;
        }
        // If the player moves to a room with super bats
        if (playerRoom == bat1 || playerRoom == bat2) {
          // Set the value of the original room
          int originalRoom = playerRoom;
          // Move the player to a random room
          playerRoom = rand() % 20 + 1;

          // Randomize the other bat to be in a room that isn't in the same room
          // as the player, the other bats, and the original room that they were
          // in

          if (bat1 == originalRoom) {
            // Randomize values until they are different from the original room
            // the player, and the other bats
            while ((bat1 == playerRoom) || (bat1 == originalRoom) ||
                   (bat1 == bat2)) {
              bat1 = rand() % 20 + 1;
            }
          }
          if (bat2 == originalRoom) {
            // Randomize values until they are different from the original room
            // the player, and the other bats
            while ((bat2 == playerRoom) || (bat2 == originalRoom) ||
                   (bat1 == bat2)) {
              bat2 = rand() % 20 + 1;
            }
          }

          // Message when bats transport player
          printf("Woah... you're flying! \n");
          printf("You've just been transported by bats to room %d.\n",
                 playerRoom);
        }

        continue;

      }
      // Invalid move
      else {
        printf("Invalid move.  Please retry. \n");
      }
      // Player shooting
    } else if ((userMove[0] == 'S' || userMove[0] == 's')) {
      // Increase the move number
      moveNum++;

      // Attempt to shoot arrow you don't have
      if (arrow > 0 && arrow != -1) {
        printf(
            "Sorry, you can't shoot an arrow you don't have.  Go find it.\n");
        continue;
      }

      // Prompt user to enter input
      printf("Enter the number of rooms (1..3) into which you want to shoot, "
             "followed by the rooms themselves: ");
      // First store the number of rooms that the user wants to shoot.
      int numRoomsChosen = -1;
      scanf(" %d", &numRoomsChosen);

      // Now depending on the number of rooms chosen, store them into an array.
      int *roomsChosen = (int *)malloc(4 * sizeof(int));
      // The first index of roomsChosen will always be the room that the player
      // is currently in
      roomsChosen[0] = playerRoom;
      // One room
      if (numRoomsChosen == 1) {
        scanf(" %d", &roomsChosen[1]);
      }
      // Two rooms
      else if (numRoomsChosen == 2) {
        scanf(" %d %d", &roomsChosen[1], &roomsChosen[2]);
      }
      // Three rooms
      else if (numRoomsChosen == 3) {
        scanf(" %d %d %d", &roomsChosen[1], &roomsChosen[2], &roomsChosen[3]);
      }
      // Otherwise there is undefined behavior
      else if (numRoomsChosen > 3) {
        // User enters more than 3 rooms to shoot arrow through
        printf(
            "Sorry, the max number of rooms is 3.  Setting that value to 3.");
        scanf(" %d %d %d", &roomsChosen[1], &roomsChosen[2], &roomsChosen[3]);
      }
      // Undefined behavior
      else {
        continue;
      }

      // Check if the user has the arrow
      if (arrow == -1) {

        // Repeat this loop for the amount of times the arrow shoots through
        for (int i = 1; i <= numRoomsChosen; i++) {
          // Attempt to shoot arrow through room that is not adjacent
          // This means that the arrow is riccocet-ing.
          if (checkAdjacent(roomsChosen[i - 1], roomsChosen[i], wumpusMap) ==
              0) {
            // Move the arrow to the lowest numbered adjacent room to the room
            // that the arrow is currently in
            printf("Room %d is not adjacent.  Arrow ricochets...\n",
                   roomsChosen[i]);
            arrow = wumpusMap[roomsChosen[i - 1] - 1][0];

            // Now check conditions while the arrow is riccocet-ing.

            // Arrow riccocets to the room that the player is in
            if (playerRoom == arrow) {
              // Arrow ricochets, and kills person
              printf("You just shot yourself, and are dying.\n"
                     "It didn't take long, you're dead.\n");
              free(roomsChosen);
              goto EXIT;
            }
            if (arrow == wumpus) {
              // Arrow ricochets, and kills Wumpus
              printf("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
                     "Accidental victory, but still you win!\n");
              free(roomsChosen);
              goto EXIT;
            }
          } else {
            // Move the arrow to the chosen room
            arrow = roomsChosen[i];
          }

          // Check if the player shot themselves
          if (arrow == playerRoom) {
            // Arrow killed player
            printf("You just shot yourself.  \n"
                   "Maybe Darwin was right.  You're dead.\n");
            free(roomsChosen);
            goto EXIT;
          }

          // Check if the room the arrow's currently in hit the Wumpus
          if (arrow == wumpus) {
            // Arrow killed Wumpus
            printf(
                "Wumpus has just been pierced by your deadly arrow! \n"
                "Congratulations on your victory, you awesome hunter you.\n");
            free(roomsChosen);
            goto EXIT;
          }
        }
      }

      // Any time the player tries to shoot, the Wumpus moves to the
      // lowest-numbered adjacent room, regardless of what sort of room the
      // Wumpus is currently in
      wumpus = wumpusMap[wumpus - 1][0];

      // free up roomsChosen
      free(roomsChosen);
    }
    // Message for invalid move
    else {
      printf("Invalid move.  Please retry. \n");
    }
  }

  // Exit the program
EXIT:

  free(userMove);

  // Loop through each index and free up its pointer
  for (int i = 0; i < 20; i++) {
    free(wumpusMap[i]);
  }

  // Free up map
  free(wumpusMap);

  // Message that prints at the end of the program
  printf("\nExiting Program ...\n");

  return 0;
}
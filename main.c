#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functions
void plains();
void path();
void cave();
void river();
void menu();

//universal checks 
int plainf = 0;
int axeme = 0;
int ogreal = 0;
int torchme = 0;

int main() {
	menu();
}



//main program
void menu()
{
	//variabeles
	char menu[100];
	char start[100] = "start";
	char end[100] = "end";
	int starting;
	int ending;

	//print main menu
	printf("Welcome to ADVENTUREGAME!");
	printf("\n");
	printf("Type 'start' to START the game\n");
	printf("Type 'end' to END the game\n");

	//input of main menu
	while (1) {
		//scan the input
		scanf_s("%s", menu, 100);

		//string compare
		starting = strcmp(menu, start);
		ending = strcmp(menu, end);

		//start the game
		if (starting == 0) {
			printf("\n");
			printf("the story begins...\n \n");
			plains();
		}

		//end the game
		if (ending == 0) {
			printf("\n");
			printf("GOOD BYE\n");
			exit(EXIT_FAILURE);
		}

		//if the input is wrong	
		else {
			printf("Would you like to START 'start' or END 'end'\n");
		}
	}
	return 0;
}


// plains
void plains() {

	char inputp[100];
	char left[100] = "left";
	char right[100] = "right";
	char end[100] = "end";
	int leftp;
	int rightp;
	int endp;

	//text
	//if first time
	if (plainf == 0) {
		printf("You wake in a grassy plain.\n");
		plainf++;
	}
	//not first time
	else {
		printf("You are in a grassy plain.\n");
	}
	printf("You see a cave to your right.\n");
	printf("You see a path to your left.\n");
	printf("What would you like to do?\n");

	while (1) {

		//input scan
		scanf_s("%s", &inputp, 100);

		leftp = strcmp(inputp, left);
		rightp = strcmp(inputp, right);
		endp = strcmp(inputp, end);

		//left
		if (leftp == 0) {
			printf("You go left\n \n");
			path();
		}

		//right 
		else if (rightp == 0) {
			printf("You go right\n \n");
			cave();
		}

		//end
		else if (endp == 0) {
			printf("GOOD BYE");
			exit(EXIT_FAILURE);
		}

		//unrecognised input
		else {
			printf("I do not recognise ");
			printf(inputp);
			printf(". Type 'help' for a list of valid inputs.\n");
		}

	}

}
//path
void path() {

	char inputa[100];
	char left[100] = "left";
	char right[100] = "right";
	char end[100] = "end";
	char axe[100] = "axe";
	int axea;
	int enda;
	int lefta;
	int righta;

	//text
	printf("You walk down a path. \n");
	printf("You are surrounded by tall trees all around you. \n");

	//if axe is there
	if (axeme == 0) {
		printf("You see an axe in a tree stump. \n");
	}
	printf("You see the plains to your right. \n");
	printf("You see a river to your left. \n");
	printf("What would you like to do?\n");

	while (1) {
		//input check
		scanf_s("%s", inputa, 100);

		lefta = strcmp(inputa, left);
		righta = strcmp(inputa, right);
		enda = strcmp(inputa, end);
		axea = strcmp(inputa, axe);
		
		//left
		if (lefta == 0) {
			printf("You go left. \n \n");
			river();
		}

		//right
		else if (righta == 0) {
			printf("You go right. \n \n");
			plains();
		}

		//end
		else if (enda == 0) {
			printf("GOOD BYE");
			exit(EXIT_FAILURE);
		}

		//axe, they already have it 
		else if (axea == 0, axeme != 0) {
			printf("You already have the axe. \n");
		}

		//take axe
		else if (axea == 0 && axeme == 0) {
			printf("You take the axe from the stump. You can now use the axe.\n");
			++axeme;
		}

		//unrecognised input
		else {
			printf("I do not recognise ");
			printf(inputa);
			printf(". Type 'help' for a list of valid inputs.\n");
		}
		
	}
}


//cave
void cave() {

	char inputc[100];
	char axe[100] = "axe";
	char right[100] = "right";
	char left[100] = "left";
	char end[100] = "end";
	int endc;
	int axec;
	int rightc;
	int leftc; 

	//text
	printf("You walk into the cave.\nIt is too dark to see.\n");
	//ogre alive
	if (ogreal == 0) {
		printf("There is a dark figure in the corner. \nIt begins to approach you, it is a large ogre. \nHe yells 'LEAVE OR YOU WILL NO LONGER BREATHE' \n");
		printf("You can use anything in your inventory against the Ogre.\n");
	}
	printf("You see the plains to your left.\n");
	printf("What would you like to do?\n");

	while (1) {
		
		//input check
		scanf_s("%s", inputc, 100); 

		rightc = strcmp(inputc, right);
		leftc = strcmp(inputc, left);
		endc = strcmp(inputc, end);
		axec = strcmp(inputc, axe);

		//end
		if (endc == 0) {
			printf("GOOD BYE");
			exit(EXIT_FAILURE);
		}

		//left
		if (leftc == 0) {
			printf("You go left. \n \n");
			plains();
		}

		//right, ogre is alive
		else if (rightc == 0 && ogreal == 0) {
			printf("The Ogre is stopping you from going right. \n");
		}

		//right, ogre is dead, no torch
		else if (rightc == 0 && ogreal != 0 && torchme == 0) {
			printf("The path is too dark to go right. \n");
		}

		//kill ogre
		else if (axec == 0 && axeme != 0 && ogreal == 0) {
			printf("You use the axe and decapitatie the Ogre.\n");
			printf("The Ogre is no longer blocking the path to the right.\n");
			++ogreal;
		}

		// right
		else if (rightc == 0 && ogreal != 0 && torchme != 0) {
			printf("Congratulations, you win!!!\n \n");
			menu();
		}

		//unrecognised input
		else{
			printf("I do not recognise ");
			printf(inputc);
			printf(". Type 'help' for a list of valid inputs.\n");
		}

	}
}


//river
void river() {

	char inputr[100];
	char left[100] = "left";
	char right[100] = "right"; 
	char end[100] = "end";
	char torch[100] = "torch";
	int leftr; 
	int torchr;
	int endr;
	int rightr;

	//text
	printf("You come accross a river, it is too wide and too deep to cross. \n");

	//torch there 
	if (torchme == 0) {
		printf("You see a boat at the shore, there is a torch in the boat.\n");
	}
	//no torch 
	else {
		printf("You see a boat near the shore.\n");
	}
	printf("You see the path to the right. \n");
	printf("What would you like to do. \n");

	while (1) {

		//input check 
		scanf_s("%s", inputr, 100); 

		rightr = strcmp(inputr, right);
		leftr = strcmp(inputr, left); 
		endr = strcmp(inputr, end); 
		torchr = strcmp(inputr, torch);

		//end
		if (endr == 0) {
			printf("GOOD BYE");
			exit(EXIT_FAILURE);
		}

		//right
		else if (rightr == 0) {
			printf("You go right. \n \n");
			path();
		}

		//left
		else if (leftr == 0) {
			printf("You can not go left. \n");
		}

		//take torch
		else if (torchr == 0) {
			printf("You take the torch. \n");
			torchme++;
		}

		//you have the torch
		else if (torchr == 0 && torchme != 0) {
			printf("You already have the torch. \n");
		}

		//unrecognised input
		else {
			printf("I do not recognise ");
			printf(inputr);
			printf(". Type 'help' for a list of valid inputs.\n");
		}
	}
}
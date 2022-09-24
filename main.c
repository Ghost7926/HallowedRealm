#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//functions
void plains();
void path();
void cave();
void river();
void menu();
void helpme();
void endsc();
void mist();
void village();
void invme();
void saveing();

//universal inputs
char left[100] = "left";
char right[100] = "right";
char end[100] = "end";
char axe[100] = "axe";
char torch[100] = "torch";
char bow[100] = "bow";
char stone[100] = "stone";
char ogre[100] = "ogre";
char help[100] = "help";
char inventory[100] = "inventory";
char save[100] = "save";

//inventory array
int inv[6];

//first time in plains
int plainf = 0;

//ogre and lady is alive
int ogreal = 0;
int ladyal = 0;

//save point ints
int svplainf = 0;
int svogreal = 0;
int svladyal = 0;
int svinv[6];

//main
int main() {
	menu();
}

/* MENU
* start here 
* if they die or win, they are sent here
*/
void menu()
{
	//variabeles
	char menu[100];
	char start[100] = "start";
	char end[100] = "end";
	int starting;
	int ending;

	//print main menu
	printf("Welcome to Hallowed Realm!");
	Sleep(1000);
	printf("\n");
	printf("Type 'start' to START the game\n");
	printf("Type 'end' to END the game\n");
	
	//reset
	plainf = 0;
	ogreal = 0;
	ladyal = 0;
	inv[0] = 0;
	inv[1] = 0;
	inv[2] = 0;
	inv[3] = 0;
	inv[4] = 0;
	inv[5] = 0;

	//use saves
	plainf = svplainf;
	ogreal = svogreal;
	ladyal = svladyal;
	inv[0] = svinv[0];
	inv[1] = svinv[1];
	inv[2] = svinv[2];
	inv[3] = svinv[3];
	inv[4] = svinv[4];
	inv[5] = svinv[5];

	if (plainf != 0) {
		printf("You have a save point in the game.\n");
	}

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
			printf("The story begins...\n \n");
			Sleep(1000);
			system("cls");
			plains();
		}

		//end the game
		if (ending == 0) {
			printf("\n");
			printf("GOOD BYE\n");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//if the input is wrong	
		else {
			printf("Would you like to START 'start' or END 'end'\n");
		}
	}
	return 0;
}

/* HELP MENU
* During the program, they can ask for the help menu to better understand the input that is accepted
*/
void helpme() {
	printf("To go left or right type: 'left' or 'right'\n");
	Sleep(300);
	printf("To use an item in your inventory type: 'nameofitem'\n");
	Sleep(300);
	printf("To check your inventory type 'inventory' \n");
	Sleep(300);
	printf("You can end the program at any time by typing: 'end' \n");
	return 0;
}

/* INVENTORY CHECK
* If they want to see what they're inventory is, this function will execute stating what items they have
*/
void invme() {
	/*
	array values and meanings
	0 = axe 
	1 = torch
	2 = bow 
	3 = stone 
	4 = ogre
	5 = cloak of levitation 
	*/

	if (inv[0] != 0) {
		printf("Axe \n");
	}

	if (inv[1] != 0) {
		printf("Torch \n");
	}

	if (inv[2] != 0) {
		printf("Bow \n");
	}

	if (inv[3] != 0) {
		printf("Stone \n");
	}

	if (inv[4] != 0) {
		printf("Ogre \n");
	}

	if (inv[5] != 0) {
		printf("Cloak of Levitation \n");
	}

	if (inv[0] == 0 && inv[1] == 0 && inv[2] == 0 && inv[3] == 0 && inv[4] == 0 && inv[5] == 0){
		printf("You have nothing... \n");
	}
}

/* SAVE GAME
* Able to save the games inventory and evolving features
*/
void saveing() {

	svinv[0] = inv[0];
	svinv[1] = inv[1];
	svinv[2] = inv[2];
	svinv[3] = inv[3];
	svinv[4] = inv[4];
	svinv[5] = inv[5];

	svplainf = plainf;
	svogreal = ogreal;
	svladyal = ladyal;

	printf("...Progress saved...\n");

}

/* PLAINS
* where the program starts when they say start in main menu 
* nothing is special in this section ATM 
* right - cave
* left - path
*/
void plains() {

	char inputp[100];
	int invp;
	int helpp;
	int leftp;
	int rightp;
	int endp;
	int savep;

	//if its their fisrt time here 
	if (plainf == 0) {
		printf("You wake in a grassy plain.\n");
		Sleep(1000);
		plainf++;
	}
	//they've been here before
	else {
		printf("You are in a grassy plain.\n");
		Sleep(1000);
	}
	printf("You see a cave to your right.\n");
	Sleep(1000);
	printf("You see a path to your left.\n");
	Sleep(1000);
	printf("What would you like to do?\n");

	while (1) {
		//input checking
		scanf_s("%s", &inputp, 100);

		leftp = strcmp(inputp, left);
		rightp = strcmp(inputp, right);
		endp = strcmp(inputp, end);
		helpp = strcmp(inputp, help);
		invp = strcmp(inputp, inventory);
		savep = strcmp(inputp, save);

		//left
		if (leftp == 0) {
			printf("You go left\n \n");
			Sleep(1000);
			path();
		}

		//right
		else if (rightp == 0) {
			printf("You go right\n \n");
			Sleep(1000);
			cave();
		}

		//help menu
		else if (helpp == 0) {
			helpme();
		}

		//end
		else if (endp == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//inventory check
		else if (invp == 0) {
			invme();
		}

		//save 
		else if (savep == 0) {
			saveing();
		}
		//unrecongnised input
		else {
			printf("I do not recognise ");
			printf(inputp);
			printf(". Type 'help' for a list of valid inputs.\n");
		}

	}

}

/* PATH 
* locaiton of the axe 
* location of the bow, secret 
* left - river 
* right - plains
*/
void path() {

	char inputa[100];
	char tree[100] = "tree";
	int inva;
	int treea;
	int helpa;
	int axea;
	int enda;
	int lefta;
	int righta;
	int savea;

	//text
	printf("You walk down a path. \n");
	Sleep(1000);
	printf("You are surrounded by tall trees all around you. \n");
	Sleep(1000);

	//if the axe is still there
	if (inv[0] == 0) {
		printf("You see an axe in a tree stump. \n");
		Sleep(1000);
	}
	printf("You see the plains to your right. \n");
	Sleep(1000);
	printf("You see a river to your left. \n");
	Sleep(1000);
	printf("What would you like to do?\n");

	while (1) {
		//input checking
		scanf_s("%s", inputa, 100);

		lefta = strcmp(inputa, left);
		righta = strcmp(inputa, right);
		enda = strcmp(inputa, end);
		axea = strcmp(inputa, axe);
		helpa = strcmp(inputa, help);
		treea = strcmp(inputa, tree);
		inva = strcmp(inputa, inventory);
		savea = strcmp(inputa, save);

		//left
		if (lefta == 0) {
			printf("You go left. \n \n");
			Sleep(1000);
			river();
		}

		//right
		else if (righta == 0) {
			printf("You go right. \n \n");
			Sleep(1000);
			plains();
		}

		//end
		else if (enda == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//axe, if they already have it
		else if (axea == 0 && inv[0] != 0) {
			printf("You already have the axe. \n");
		}

		//take axe
		else if (axea == 0 && inv[0] == 0) {
			printf("You take the axe from the stump. You can now use the axe.\n");
			inv[0] = 1;
		}
		
		//tree, taking bow
		else if (treea == 0 && inv[2] == 0) {
			printf("You walk up to one of the trees. \n");
			Sleep(1000);
			printf("You see an arrow stuck in the tree and a bow on the ground. \n");
			Sleep(1000);
			printf("You take the bow and arrow. \n");
			inv[2] = 1;
		}

		//they have the bow
		else if (treea == 0 && inv[2] != 0) {
			printf("You already have the bow.\n");
			Sleep(1000);
		}

		//help menu
		else if (helpa == 0) {
			helpme();
		}

		//inventory check
		else if (inva == 0) {
			invme();
		}

		//save game
		else if (savea == 0) {
			saveing();
		}

		//unrecognised input
		else {
			printf("I do not recognise ");
			printf(inputa);
			printf(". Type 'help' for a list of valid inputs.\n");
		}

	}
}

/* CAVE
* Ogre boss fight
* they can kill the ogre or take the ogre with the stone 
* left - plains
* right - mist
*/
void cave() {

	//variables
	char inputc[100];
	int invc;
	int bowc;
	int stonec;
	int torchc;
	int helpc;
	int endc;
	int axec;
	int rightc;
	int leftc;
	int savec;

	//text
	printf("You walk into the cave.\n");
	Sleep(1000);

	//they dont have the torch
	if (inv[1] == 0) {
		printf("It is too dark to see.\n");
		Sleep(1000);
	} 

	//if the ogre is alive
	if (ogreal == 0) {
		printf("There is a dark figure in the corner. \n");
		Sleep(1000);
		printf("It begins to approach you, it is a large ogre. \n");
		Sleep(1000);
		printf("He yells 'LEAVE OR YOU WILL NO LONGER BREATHE' \n");
		Sleep(1000);
		printf("You can use anything in your inventory against the Ogre.\n");
		Sleep(1000);
	}
	printf("You see the plains to your left.\n");
	Sleep(1000);

	//if they have the torch
	if (inv[1] != 0) {
		printf("The cave goes deeper to the right. \n");

	}
	printf("What would you like to do?\n");

	while (1) {
		//input check 
		scanf_s("%s", inputc, 100);

		rightc = strcmp(inputc, right);
		leftc = strcmp(inputc, left);
		endc = strcmp(inputc, end);
		axec = strcmp(inputc, axe);
		helpc = strcmp(inputc, help);
		torchc = strcmp(inputc, torch);
		stonec = strcmp(inputc, stone);
		bowc = strcmp(inputc, bow);
		invc = strcmp(inputc, inventory);
		savec = strcmp(inputc, save);

		//end 
		if (endc == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//left 
		else if (leftc == 0) {
			printf("You go left. \n \n");
			Sleep(1000);
			plains();
		}

		//right, ogre is alive
		else if (rightc == 0 && ogreal == 0) {
			printf("The Ogre is stopping you from going right. \n");
		}

		//right, ogre is dead, they dont have torch
		else if (rightc == 0 && ogreal != 0 && inv[1] == 0) {
			printf("The path is too dark to go right. \n");
		}

		//use axe, they have axe, ogre is alive
		else if (axec == 0 && inv[0] != 0 && ogreal == 0) {
			printf("You use the axe and decapitatie the Ogre.\n");
			Sleep(1000);
			printf("The Ogre is no longer blocking the path to the right.\n");
			++ogreal;
		}

		//stone easter egg
		else if (stonec == 0 && ogreal == 0 && inv[3] != 0) {
			printf("You reach into you pocket and take out the stone. \n");
			Sleep(1000);
			printf("You hand it to the ogre.\n");
			Sleep(1000);
			printf("He drops to his knees and says, 'YOU HAVE GIVEN ME A GREAT GIFT...'\n");
			Sleep(1000);
			printf("'I WILL BE YOUR SERVANT'\n");
			Sleep(1000);
			printf("Ogre has been added to your inventory.\n");
			++ogreal;
			inv[4] = 1;
			inv[3] = 0;
		}

		//right, ogre is dead, they have torch
		else if (rightc == 0 && ogreal != 0 && inv[1] != 0) {
			printf("You go right.\n \n");
			Sleep(1000);
			mist();
		}

		//use torch, ogre is alive
		else if (torchc == 0 && ogreal == 0) {
			printf("You wave the torch infront of the Ogre. \n");
			Sleep(1000);
			printf("He takes his club and he breaks your spine. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}
		
		else if (bowc == 0 && inv[2] != 0) {
			printf("You take out the bow and draw back the string. \n");
			Sleep(1000);
			printf("You fire the arrow at the Ogre striking him in the leg. \n");
			Sleep(1000);
			printf("The Ogre lifts his club and slams it into your head killing you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//help menu
		else if (helpc == 0) {
			helpme();
		}

		else if (invc == 0) {
			invme();
		}

		//save game
		else if (savec == 0) {
			saveing();
		}

		//unrecognised input
		else {
			printf("I do not recognise ");
			printf(inputc);
			printf(". Type 'help' for a list of valid inputs.\n");
		}

	}
}

/* RIVER
* location of the torch
* location of the stone, secret
* left - village, secret
* right - path
*/
void river() {

	char inputr[100];
	char boat[100] = "boat";
	char river[100] = "river";
	int invr;
	int riverr;
	int boatr;
	int helpr;
	int leftr;
	int torchr;
	int endr;
	int rightr;
	int saver;

	//text
	printf("You come accross a river, it is too wide and too deep to cross. \n");
	Sleep(1000);
	printf("You see a village on the other side. \n");
	Sleep(1000);
	//torch is there
	if (inv[1] == 0) {
		printf("You see a boat at the shore, there is a torch in the boat.\n");
		Sleep(1000);
	}

	//torch is not there
	else {
		printf("You see a boat near the shore.\n");
		Sleep(1000);
	}
	printf("You see the path to the right. \n");
	Sleep(1000);
	printf("What would you like to do. \n");

	while (1) {
		//input check 
		scanf_s("%s", inputr, 100);

		rightr = strcmp(inputr, right);
		leftr = strcmp(inputr, left);
		endr = strcmp(inputr, end);
		torchr = strcmp(inputr, torch);
		helpr = strcmp(inputr, help);
		boatr = strcmp(inputr, boat);
		riverr = strcmp(inputr, river);
		invr = strcmp(inputr, inventory);
		saver = strcmp(inputr, save);

		//end
		if (endr == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//right 
		else if (rightr == 0) {
			printf("You go right. \n \n");
			Sleep(1000);
			path();
		}

		//left, dont have cloak
		else if (leftr == 0 && inv[5] == 0) {
			printf("You can not go left. \n");
			Sleep(1000);
		}

		//left and they have the cloak
		else if (leftr == 0 && inv[5] != 0) {
			printf("You float over the river to the other side.\n \n");
			Sleep(1000);
			village();
		}

		//they already have the torch
		else if (torchr == 0 && inv[1] != 0) {
			printf("You already have the torch. \n");
			Sleep(1000);
		}

		//take torch
		else if (torchr == 0 && inv[1] == 0) {
			printf("You take the torch. \n");
			inv[1] = 1;
		}

		//they ask to use boat
		else if (boatr == 0) {
			printf("The boat is too damaged to use. \n");
			Sleep(1000);
		}

		//help menu
		else if (helpr == 0) {
			helpme();
		}

		//they take the stone
		else if (riverr == 0 && inv[3] == 0) {
			printf("You walk up to the river edge. \n");
			Sleep(1000);
			printf("You see a shinny red stone just under the water. \n");
			Sleep(1000);
			printf("You pick up the stone and put it in your pocket. \n");
			inv[3] = 1;
		}

		//they already have the stone
		else if (riverr == 0 && inv[3] != 0) {
			printf("You already have the stone. \n");
		}

		//inventory
		else if (invr == 0){
			invme();
		}

		//save game
		else if (saver == 0) {
			saveing();
		}

		//unrecognised input 
		else {
			printf("I do not recognise ");
			printf(inputr);
			printf(". Type 'help' for a list of valid inputs.\n");
		}
	}
}

/* LADY OF THE MIST
* end screen for the regular ending
* ogre can kill for secret ending
* left - cave 
* right - NA 
*/
void mist() {
	char inputm[100];
	char yes[100] = "yes";
	char no[100] = "no";
	int invm;
	int ogrem;
	int helpm;
	int endm;
	int leftm;
	int rightm;
	int yesm;
	int nom;
	int savem;
	
	printf("You go deeper inside the cave. \n");
	Sleep(1000);
	printf("You become surrounded by a misty fog. \n");
	Sleep(1000);

	//the lady is alive
	if (ladyal == 0){
		printf("There is a floating cloaked figure approaching you. \n");
		Sleep(1000);
		printf("'I am the Lady of the Mist. You have made it to the end of my Hallowed Realm.' \n");
		Sleep(1000);
		printf("'Would you like to return to the after life?' \n");
	}
	else {
		printf("What would you like to do? \n");
	}

	while (1) {

		scanf_s("%s", inputm, 100);

		endm = strcmp(inputm, end);
		leftm = strcmp(inputm, left);
		rightm = strcmp(inputm, right);
		yesm = strcmp(inputm, yes);
		nom = strcmp(inputm, no);
		helpm = strcmp(inputm, help);
		ogrem = strcmp(inputm, ogre);
		invm = strcmp(inputm, inventory);
		savem = strcmp(inputm, save);

		//end
		if (endm == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//left
		else if (leftm == 0) {
			printf("You go left. \n \n");
			Sleep(1000);
			cave();
		}
		
		//right 
		else if (rightm == 0) {
			printf("You can't go right. \n");
			Sleep(1000);
		}

		//yes and the lady is alive
		else if (yesm == 0 && ladyal == 0) {
			printf("You're vision begins to brighten. \n");
			Sleep(2000);
			printf("You are unable to see annything. \n");
			Sleep(2000);
			printf("Suddenly everything goes dark. \n");
			Sleep(2000);
			endsc();
		}
		
		//no and the lady is dead
		else if (nom == 0 && ladyal == 0) {
			printf("'Come back to me when you want to return to the after life.' \n");
			Sleep(1000);
		}

		//you have the ogre and the lady is alive
		else if (ogrem == 0 && inv[4] != 0 && ladyal == 0) {
			printf("You tell the ogre to kill the Lady.\n");
			Sleep(1000);
			printf("He lifts his club and swings it through the floating cloak. \n");
			Sleep(1000);
			printf("The cloak falls to the ground. You take it and put it around your shoulders. \n");
			Sleep(1000);
			printf("You begin to levitate. \n");
			++ladyal;
			inv[5] = 1;
		}

		//the lady is already dead
		else if (ogrem == 0 && inv[4] != 0 && ladyal != 0) {
			printf("The lady is already dead. \n");
			Sleep(1000);
		}

		//help 
		else if (helpm == 0) {
			helpme();
		}

		//inventory check
		else if (invm == 0) {
			invme();
		}

		//save game
		else if (savem == 0) {
			saveing();
		}

		//input unrecognised
		else {
			printf("I do not recognise ");
			printf(inputm);
			printf(". Type 'help' for a list of valid inputs.\n");
		}
	}
}

/* VILLAGE 
* end sequence of the secret ending
* once you are here, its either bow or death
* left - death
* right - death
*/
void village() {

	char inputv[100];
	int invv;
	int helpv;
	int ogrev;
	int stonev;
	int axev;
	int torchv;
	int bowv;
	int leftv;
	int rightv;
	int endv;
	int savev;
	inv[4] = 0;
	
	printf("The village is surrounded by mountains by all sides, only open towards the river.\n");
	Sleep(1000);
	printf("You hear the foot steps of something behide you. \n");
	Sleep(1000);
	printf("You turn to see a creature unlike anything you have ever seen before. \n");
	Sleep(1000);
	printf("It growls and begins to sprint at you. \n");
	Sleep(1000);
	printf("What will you do? \n");
	printf("Be wise in your choice, you only have time for one move.\n");

	while (1) {

		scanf_s("%s", inputv, 100);

		endv = strcmp(inputv, end);
		leftv = strcmp(inputv, left);
		rightv = strcmp(inputv, right);
		axev = strcmp(inputv, axe);
		ogrev = strcmp(inputv, ogre);
		helpv = strcmp(inputv, help);
		stonev = strcmp(inputv, stone);
		bowv = strcmp(inputv, bow);
		torchv = strcmp(inputv, torch);
		invv = strcmp(inputv, inventory);
		savev = strcmp(inputv, save);

		//end
		if (endv == 0) {
			printf("GOOD BYE");
			Sleep(1000);
			exit(EXIT_FAILURE);
		}

		//left
		else if (leftv == 0) {
			printf("You try to run into the village to hide but the creature catches up to you. \n");
			Sleep(1000);
			printf("Its claws rip though your back and kill you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//right
		else if (rightv == 0) {
			printf("You run at the creature and attempt to go around it to get back over the river.\n");
			Sleep(1000);
			printf("The creature grabs you and throws you to the ground. \n");
			Sleep(1000);
			printf("It rips at your neck with its calws killing you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//use axe, they die
		else if (axev == 0) {
			printf("You ready your axe and wait for the creature to get close enough to strike.\n");
			Sleep(1000);
			printf("You swing your axe but it deflects it and sticks its claws into you stomach killing you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//use torch, they die
		else if (torchv == 0) {
			printf("You take out the torch and light it. \n");
			Sleep(1000);
			printf("You hit the creature in attempt to light it on fire. \n");
			Sleep(1000);
			printf("It slashes you with its claws killing you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//use ogre, they die
		else if (ogrev == 0) {
			printf("You call for the Ogres help to stop the creature.\n");
			Sleep(1000);
			printf("You forget that he was unable to cross the river with you. \n");
			Sleep(1000);
			printf("The creature kills you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//use stone, they die
		else if (stonev == 0) {
			printf("You reach into your pocket to take out the stone, forgetting you already gave the stone to the Ogre. \n");
			Sleep(1000);
			printf("You are out of time, the creature has caught you. It kills you. \n \n");
			Sleep(1000);
			printf("GAME OVER\n \n");
			system("pause");
			system("cls");
			menu();
		}

		//use bow, they live
		else if (bowv == 0 && inv[2] != 0) {
			printf("You nock an arrow and draw the string back. \n");
			Sleep(2000);
			printf("The creature continues to sprint at you. \n");
			Sleep(2000);
			printf("You release the string. \n");
			Sleep(2000);
			printf("The arrow pierces the creatures eye. \n");
			Sleep(2000);
			printf("It screeches and drops to the ground. \n");
			Sleep(2000);
			printf("Behind the creature you see a man in robes. \n");
			Sleep(2000);
			printf("Hello warrior. You have completed my challenge. \n");
			Sleep(2000);
			printf("You will be allowed into my ranks of angles to help protect the Heavens. \n");
			Sleep(2000);
			endsc();
		}

		//help
		else if (helpv == 0) {
			helpme();
		}

		//inventory check
		else if (invv == 0) {
			invme();
		}

		//save game
		else if (savev == 0) {
		saveing();
		}

		//input not recognised
		else {
			printf("I do not recognise ");
			printf(inputv);
			printf(". Type 'help' for a list of valid inputs.\n");
		}
	}
}

/* END SCREEN
* if you win through either mist ending or village ending, you are sent here 
*/
void endsc() {
	system("cls");
	printf("Congratulations!\n");
	Sleep(2000);
	printf("You have completed the Hallowed Realm! \n");
	Sleep(2000);
	system("pause");
	svplainf = 0;
	svogreal = 0;
	svladyal = 0;
	svinv[0] = 0;
	svinv[1] = 0;
	svinv[2] = 0;
	svinv[3] = 0;
	svinv[4] = 0;
	svinv[5] = 0;
	system("cls");
	menu();
}

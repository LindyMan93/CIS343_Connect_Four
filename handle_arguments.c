#include <stdlib.h>
#include "handle_arguments.h"
#include <argp>

// Title
const char *argp_program_version = "Connect4 Project Release 1.0";

// Developer Contact
const char *argp_program_bug_address = "lindenbn@mail.gvsu.edu";

// Documentation string.
char doc[] = "Connect Four game that is able to create different size boards and win lengths.";

// Description of the required arguments we accept.
char args_doc[] = "";

// This option struct is for any optional arguments.
struct argp_option options[] = {
        {"width", 'w', "Width", 0, "This will allow the user to change width" },
        {"height", 'h', "Height", 0, "This will allow the user to change height" },
        {"square", 's', "Square", 0, "This allows the user to make the board a square" },
        {"connect", 'c', "Connect", 0, "This allows the user to change the amount of pieces in a row to win" },
        {"load", 'l', "Load", 0, "This allows the user to load a saved game"}
};

// Argp requires us to pass these values in via the argp struct
struct argp argp = { options, parse_opt, args_doc, doc };
// Declare a variable called arguments that is also an
// arguments struct.  Remeber - we can't use the struct
// by just describing it.  We also need to make one.  Sort
// of similar to how we instantiate an object in Java.
struct arguments arguments;

// Our custom function for setting up values once they
// have been parsed from the command line args.
error_t parse_opt(int key, char* arg, struct argp_state *state){
    struct arguments *arguments = state->input;
    switch(key){
        case 'w':
            arguments->width = atoi(arg);;
            break;
        case 'h':
            arguments->height = atoi(arg);
            break;
        case 's':
            arguments->width = atoi(arg);
            arguments->height = atoi(arg);
            break;
        case 'c':
            arguments->connect = atoi(arg);
            break;
        case 'l':
            arguments->load_file = arg;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

// Here we setup some default values and override them
// if we get new values from the commandline.
void setup(int argc, char** argv, struct arguments *gameArgs){
    // Default of first, second, and load_file
    // char* load_file = NULL;
    // Call argp to do its thing.
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    // Return values are in the arguments struct.  Pull
    // them out if they are there.
	
	*gameArgs = arguments;
}


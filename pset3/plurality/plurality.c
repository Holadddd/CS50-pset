#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // 判斷候選人名單
    for(int i = 0; i < MAX; i++)
	{
	   if (candidates[i].name == NULL)
		   {
		       continue;
		   }
		//Compare two string
	    int compareResult = strcmp(candidates[i].name, name);
	//需要以字元判斷
	    if (compareResult == 0)
		    {
		       //投票
		       candidates[i].votes += 1;
		       return true;
		    }
	}
	return false;
}

// // Print the winner (or winners) of the election
// void print_winner(void)
// {
// 	int highestVotes = 0;
// 	//單純用字串可降低複雜度
// 	string winner;

// 	for (int i = 0; i < MAX; i++)
// 	{
// 		if (candidates[i].votes > highestVotes)
// 		{
// 		highestVotes = candidates[i].votes;
// 		winner = candidates[i].name;
// 		}
// 		else if (candidates[i].votes == highestVotes)
// 		{
// 		    winner = malloc(strlen(winner) + 1 + strlen(candidates[i].name));
// 		    //先換行
// 		    strcat(winner, "\n");
// 		    for (int j = 0, n = strlen(candidates[i].name); j < n; j++)
// 		    {
// 		       strcat(winner, &candidates[i].name[j]);
// 		    }
// 		}
// 	}
// 	printf("The winner is %s\n", winner);
// }

void print_winner(void)
{
	int highestVotes = 0;

	int winnerCount = 1;
	string winner[MAX];

	for (int i = 0; i < MAX; i++)
	{
		if (candidates[i].votes > highestVotes)
		{
			winnerCount = 1;
			//Clear winner
			for (int j = 0; j <MAX; j++)
			{
			winner[j] = NULL;
			}
		highestVotes = candidates[i].votes;
		winner[0] = candidates[i].name;
		}
		else if (candidates[i].votes == highestVotes)
		{
		winnerCount += 1;
		//同樣的票數
		winner[winnerCount - 1] = candidates[i].name;
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		if (winner[i] != NULL)
		{
		printf("%s\n", winner[i]);
		}
	}
}

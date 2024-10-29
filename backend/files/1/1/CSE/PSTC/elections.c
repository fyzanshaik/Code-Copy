#include<stdio.h>
void main() {
    int a[30] , voters ,cse=0 , it=0 ,mech=0 ,eee=0 , ece=0;
    printf("There are 5 Nominees\nNot Voting is A crime\nRight to VOTE");
    printf("\nCSE ID = 1 ; IT ID = 2 ; ECE ID = 3 ; EEE = 4 ; MECH = 5\n");
    printf("Enter No.of Voters : ");
    scanf("%d",&voters);
    for ( int i=0 ; i<voters ; i++ ) {
        printf("\nCandidate %d Enter your Vote Sir/Mam : ",i+1);
        scanf("%d",&a[i]);
        if ( a[i] == 1 ) {
            cse++;
        } else if ( a[i] == 2) {
            it++;
        } else if ( a[i] == 3 ) {
            ece++;
        } else if ( a[i] == 4 ) {
            eee++;
        } else if ( a[i] == 5 ) {
            mech++;
        }
    }
    if ( cse>it && cse>ece && cse>eee && cse>mech ) {
        printf("\nElection Winner is CSE with %d/%d\n",cse,voters);
    } else if ( it>cse && it>ece && it>eee && it>mech ) {
        printf("\nElection Winner is IT with %d/%d\n",it,voters);
    } else if ( ece>it && ece>cse && ece>eee && ece>mech ) {
        printf("\nElection Winner is ECE with %d/%d\n",ece,voters);
    } else if ( eee>it && eee>ece && eee>cse && eee>mech ) {
        printf("\nElection Winner is EEE with %d/%d\n",eee,voters);
    } else if ( mech>it && mech>ece && mech>eee && mech>cse ) {
        printf("\nElection Winner is MECH with %d/%d\n",mech,voters);
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



typedef struct Node
{
    
    long int info;
    struct Node *next;
    
}Node;



typedef struct List
{
    
    struct List *next;
    Node *node;
    
}List;



Node *start_1D = NULL , *start_k = NULL;                                         // Globally Declared
Node *end_1D , *end_k , *temp_1D , *temp_k , *save;
List *start_2D , *end_2D , *temp_2D;



Node* Sorting( Node *start )                                                     // Sorting Function
{
    
    long int a;
    Node *temp , *temp2;
    
    for( temp = start; temp != NULL; temp = temp->next )
    {
        
        for( temp2 = temp->next; temp2 != NULL; temp2 = temp2->next )
        {
            
            if( temp->info > temp2->info )
            {
                
                a = temp->info;
                temp->info = temp2->info;
                temp2->info = a;
                
            }
            
            
        }
        
    }
    
    return start;
    
    
}




Node* createNode(long data) {
    Node* n = malloc(sizeof(Node));
    n->info = data;
    n->next = NULL;
    return n;
}


Node *Sort_List(Node *subList) {
    Node *sorted = NULL;
    Node *tempHead;
    Node *tempNode;
    Node *tempSort;
    Node *tempNext;
    
    tempHead = subList;
    tempNode = createNode(tempHead->info);
    sorted = tempNode;
    tempHead = tempHead->next;
    
    while(tempHead != NULL) {
        tempNode = createNode(tempHead->info);
        tempSort = sorted;
        tempNext = tempSort->next;
        if(sorted->info >= tempHead->info) {
            tempNode->next = sorted;
            sorted = tempNode;
        }
        else {
            while((tempSort->next != NULL) && (tempNode->info >= tempNext->info) && (tempNode->info >= tempSort->info) && (tempNext != NULL) ) {
                
                tempNext = tempSort->next;
                if((tempNode->info >= tempNext->info)  && (tempNext != NULL) && (tempSort->next != NULL)) {
                    tempSort = tempSort->next;
                }
            }
            //swap
            if(tempNext != NULL) {
                tempNext = tempSort->next;
                tempSort->next = tempNode;
                tempNode->next = tempNext;
            }// put it in the end
            else if(tempNext == NULL) {
                tempSort->next = tempNode;
                tempNode->next = NULL;
            }
        }
        tempHead = tempHead->next;
    }
    

    return sorted;
}




int main()
{
    
    
    FILE *fp1 , *fp2 , *fp3;
    Node *current_k , *previous_k = NULL , *save_1D;
    clock_t time , time1 , time2 , time3 , time4;
    double d , d1 = 0 , d2 = 0 , d3 = 0 , d4 = 0;
    long int i = 0, j, k = 1 , n = 0 , count = 1 , l , size , value, integer;
    
    fp1 = fopen("1000.txt","r");
    fp2 = fopen("sequence.txt","w");
    fp3 = fopen("output.txt","w");
    
    if( fp1 == NULL )                                                       // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND!!\n\n\n");
        exit(1);
        
    }

    fscanf(fp1,"%ld",&size);
    
    
    while( (fscanf(fp1,"%ld",&integer) ) != EOF)                            // Inputting Integers Into A Link-List
    {
        
        temp_1D = (Node*) malloc (sizeof(Node));
        
        temp_1D->info = integer;
        
        temp_1D->next = NULL;
        
        
        if(start_1D == NULL)
        {
            
            start_1D = temp_1D;
            end_1D = temp_1D;
            
        }
        
        else
        {
            
            end_1D->next = temp_1D;
            end_1D = temp_1D;
            
        }
        
        
    }



    while( k < size )                                                       // Generating The Values Of k
    {
        
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2 , (n-i) ) * pow ( 3 , i );                      // Formula For Pyramid Form
                
                if( k > size )
                break;
                
                if( i == n )
                {
                    
                    value = k;                                              // Saving Last Right Corner From Pattern
                    
                }
                
                
            }
            
            
        }
        
        n++;
        
        
    }

 
    k = 1;
    n = 0;
    
    
    
    while( k != value )                                                     // Copying Values Of k To A File
    {
        
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2,(n-i) ) * pow ( 3,i );
                
                if( k > size )
                break;
            
                fprintf(fp2,"%ld\n",k);
                
            }
            
            
        }
        
        n++;
        
        
    }
    
    
    fclose(fp2);
    
    fp2 = fopen("sequence.txt","r");
    
    
    if( fp2 == NULL )                                                        // Checking If File Is Empty
    {
        
        printf("\n\nFILE NOT FOUND!!\n\n\n");
        exit(1);
        
    }

    
    while( (fscanf(fp2,"%ld",&integer) ) != EOF)                            // Inputting Values Of k Into A Link-List
    {
        
        temp_k = (Node*) malloc (sizeof(Node));
        
        temp_k->info = integer;

        temp_k->next = NULL;
        
        
        if( start_k == NULL )
        {
            
            start_k = temp_k;
            end_k = temp_k;
            
        }
        
        else
        {
            
            end_k->next = temp_k;
            end_k = temp_k;
            
        }
        
        
    }
    
    
    
    temp_k = start_k;
        
    while( temp_k != NULL )                                                   // Reversing The Values Of K
    {
            
        current_k = temp_k->next;
        temp_k->next = previous_k;
        previous_k = temp_k;
        temp_k = current_k;
            
    }
    
    
    start_k = previous_k;


    
    /*  SHELL SORTING  */
    
 
    
    temp_k = start_k;
    
    time = clock();         		                                          // Start Time
    
    
    while( temp_k != NULL )                                                  // Selecting Value Of K 
    {
 
        k = temp_k->info;
        start_2D = NULL;
        temp_1D = start_1D;
        i = 0;
        
        time1=clock();
        
        while( temp_1D != NULL )                                             // 1D -> 2D
        {
           
            for( ; i < k ; i++ )
            {
                
                temp_2D = (List*) malloc (sizeof(List));
            
                save_1D = temp_1D->next;
                temp_1D->next = NULL;
                temp_2D->node = temp_1D;
                temp_2D->next = NULL;
                
                if( start_2D == NULL )
                {
                    
                    start_2D = temp_2D;
                    end_2D = temp_2D;
                    
                }
                
                else
                {
                    
                    end_2D->next = temp_2D;
                    end_2D = temp_2D;
                    
                }
                
                temp_1D = save_1D;
                
                if( i == k - 1 )
                temp_2D = start_2D;
            
            }
            
            save_1D = temp_1D->next;
            
            if( temp_2D == NULL )
            temp_2D = start_2D;
            
            temp_1D->next = temp_2D->node;
            temp_2D->node = temp_1D;
            temp_2D = temp_2D->next;
            temp_1D = save_1D;
            
        }
        
        d1 = ( clock() - time1 ) / (double)CLOCKS_PER_SEC + d1;
        
        time2=clock();
        
        for( temp_2D = start_2D ; temp_2D != NULL ; temp_2D = temp_2D->next )           // Calling Sorting Function
        temp_2D->node = Sorting(temp_2D->node);
        
        d2 = ( clock() - time2 ) / (double)CLOCKS_PER_SEC + d2;
    
        start_1D = NULL;
        temp_2D = start_2D;
        l = 0;
    
        time3=clock();
        
        while( l != size )                                                              // 2D -> 1D
        {
            
            l++;
            
            temp_1D = temp_2D->node;
            
            temp_2D->node = temp_1D->next;
            temp_2D = temp_2D->next;
            
            temp_1D->next = NULL;
            
            if( temp_2D == NULL )
            temp_2D = start_2D;
            
            if( start_1D == NULL )
            {
                
                start_1D = temp_1D;
                end_1D = temp_1D;
                
            }
            
            else
            {
                
                end_1D->next = temp_1D;
                end_1D = temp_1D;
                
            }
            
            
        }
        
        d3 = ( clock() - time3 ) / (double)CLOCKS_PER_SEC + d3;
    
        temp_k = temp_k->next;
        
        temp_2D = start_2D;
        
        time4=clock();
        
        while( temp_2D != NULL )                                                   // Freeing 2D Link List
        {
            
            start_2D = temp_2D->next;
            free(temp_2D);
            temp_2D = start_2D;
            
        }
       
        d4 = ( clock() - time4 ) / (double)CLOCKS_PER_SEC + d4;

    }


    d = ( clock() - time ) / (double)CLOCKS_PER_SEC;                            // End Time
    
    printf("\n\n\nSORTING TIME: %f\n\n\n\n",d);                                 // Printing Time Taken For Sorting
    printf("\nSTEP 1 : %f\n",d1);
    printf("\nSTEP 2 : %f\n",d2);
    printf("\nSTEP 3 : %f\n",d3);
    printf("\nSTEP 4 : %f\n\n",d4);

    fprintf( fp3 , "%ld\n" , size );

 
    for( temp_1D = start_1D ; temp_1D != NULL ; temp_1D = temp_1D->next )      // Inputting Sorted Integers To File
    {
        
        fprintf(fp3,"%ld\n",temp_1D->info );
        
    }
    
    
    temp_1D = start_1D;
    
    while( temp_1D != NULL )                                                   // Freeing 1D Link List
    {
        
        save_1D = temp_1D->next;
        free(temp_1D);
        temp_1D = save_1D;
        
    }
    
    
    temp_k = start_k;
    
    while( temp_k != NULL )                                                     // Freeing Link List Of K
    {
        
        save_1D = temp_k->next;
        free(temp_k);
        temp_k = save_1D;
        
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    
    return 0;
    
    
    
}



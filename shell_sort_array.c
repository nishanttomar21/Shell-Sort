#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main()
{
    
    
    FILE *fp1 , *fp2 , *fp3;
    clock_t start;                                            // Initialising The Start Of Clock
    double d;
    int i = 0, j, k = 1,  n = 1, count = 1, size, temp;
    
    fp1 = fopen("1000.txt","r");
    fp2 = fopen("sequence.txt","w");
    fp3 = fopen("output.txt","w");
    
    if( fp1 == NULL )
    {
        
        printf("\n\nFILE NOT FOUND!!\n\n\n");
        exit(1);
        
    }
    
    fscanf(fp1,"%d",&size);
    
    int *arr = (int*) malloc (size * sizeof(int));
    int *a = (int*) malloc (size * sizeof(int));
    
    while( (fscanf(fp1,"%d",&a[i])) != EOF )                 // Inputting The Integers To An Array
    {
        
        i++;
        
    }
    
    while( k < size )                                        // Generating The Values Of k
    {
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2 , (n-i) ) * pow ( 3 , i );		 // Formula For Pyramid Form
                
                if( k > size )
                break;
                
                if( i == n )
                {
                    
                    temp = k;                                // Saving Last Right Corner From Pattern
                    
                }
                
                
            }
            
            
        }
        
        n++;
        
        
    }

 
    k = 1;
    n = 1;
    
    arr[0] = 1;
    
    fprintf( fp2 , "%d\n" , arr[0] );
    
    while( k != temp )                                       // Copying Values Of k To An Array & File
    {
        
        for( i = 0 ; i <= n ; i++ )
        {
            
            if( k < size )
            {
                
                k = pow ( 2,(n-i) ) * pow ( 3,i );
                
                if( k > size )
                break;
                
                arr[count++] = k;
                fprintf(fp2,"%d\n",k);
                
            }
            
            
        }
        
        n++;
        
        
    }

    
    /*  SHELL SORTING  */
    
    
    
    start = clock();                                            // Start Time
    
    
    for( k = temp ; count >= 0 ; k = arr[--count] )            // Selecting Value Of K From The Last
    {
        
        for( j = 0 ; j < size ; j++ )
        {
            
            temp = a[j];
            i = j - k;
            
            while( (i >= 0) && (a[i] > temp) )
            {
                
                a[i+k] = a[i];
                a[i]=temp;
                i = i - k;

            }
            
            
        }
        
        
    }
    
    
    
    d = ( clock() - start ) / (double)CLOCKS_PER_SEC;                   // End Time
    
    printf("\n\n\nSORTING TIME: %f\n\n\n\n",d);
    
    fprintf( fp3 , "%d\n" , size );

    for( i = 0; i < size; i++ )
    {
        
        fprintf(fp3,"%d\n",a[i] );                                     // Inputting Sorted Integers To File
        
    }
    
    
    free(arr);
    free(a);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
    return 0;
    
    
    
}



#include <stdio.h>
#include <stdlib.h>

//functions
void heapify(int *heap, int start, int end);
void buildheap(int* heap, int n);
void heapsort(int* heap, int n);
void intswap (int* a, int* b);

//main function
int main() {
    int *list; //unsorted list of values ot sort
    int n;     //number of values to sort
    int i;     //loop control variable

    //asking user for the number of values to sort
    printf ("\nHow many numbers are we sorting here, dog?");
    scanf("%d", &n);
    
    //in theory, there should be code here to check if the number
    //makes sense, e.g., is not zero, a negative number, a number that is
    //too large to store in an int, etc.

    //allocating for the list
    list = (int *) malloc (n * sizeof(int));
    
    //prompts user for values to sort and reads them in
    //again, in theory, the program should check that the number of
    //values is the number that was entered above, but we will pretend we
    //trust the user here
    printf ("\nEnter the values to be sorted: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &(list[i])));
    }
    
    //sorts the list in ascending order
    heapsort(list, n);
    
    //prints the sorted list
    printf ("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    
    return 0;
}

//given a list of integers, this function will sort them
//using the heapsort algorithm
void heapsort(int* heap, int n)
{
    int i;     //loop control variable 

    buildheap (heap, n); //constructs the heap for the first time
    
    //this loop continually takes the top node of the heap,
    //swaps it with the last child, and reconstructs the heap
    //without the last child until there are no nodes to
    //construct a heap with
    for (i = n - 1; i > 0; i--) {
    	intswap (&(heap[0]), &(heap[i]));
	   	heapify (heap, 0, i - 1);
    }
}

//this function heapifies every parent in an unsorted tree
//until the tree becomes a heap
void buildheap (int* heap, int n) {
    int i;                //loop control variable
    int end = n - 1;      //the index for the last child in the heap
    
    //this loop will heapify for every parents in the tree
    for(i = end / 2; i >= 0; i--) { 
	    heapify (heap, i, end);
    }
}

//this function continually swaps parents out with their
//largest child, until the segment of the tree it was sent (assuming it
//is everything under the head node it was sent) becomes
//a legitamite heap
void heapify (int *heap, int start, int end) {
    int last = ((end + 1) / 2);        //the last child in the whole tree    
    int lchild;                        //the head node's left child
    int rchild;                        //right child
    int largest;                       //largest of the children

    //this loop continues to run as long as our head node is still a parent
    while (start < last) {
        //identifies the left and right child of the head
        lchild = (2 * start) + 1;
        rchild = lchild + 1;

        //determines which child is bigger
        if (rchild <= end && heap[lchild] < heap[rchild]) {
            largest = rchild;
        }
        else {
            largest = lchild;
        }

        //switches the head and the larger child, if the larger child
        //is larger than the head
        if (heap[largest] > heap[start]) {
            intswap (&(heap[largest]), &(heap[start]));
            start = largest;
        } 
        else {
            return;   
        }
    }
}

//clever way to swap ints ;P
void intswap (int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
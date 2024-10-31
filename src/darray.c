#include "/home/seth/Desktop/darray-assignmentSF-master/include/darray.h"
#include <stdlib.h>
#include <stdio.h>

struct darray
{
    int size;
    int *thearray;
};


darray *da_create()
{

    darray *dar = malloc(sizeof(darray));
    dar->thearray = malloc(sizeof(int));


    if(dar == NULL)
    {
        return NULL;
    }

    return dar;

}

int *da_get(darray *array, size_t idx)
{
    if(idx >= da_size(array))
    {
        return NULL;
    }
    if(idx < 0)
    {
        return NULL;
    }


    return &(array->thearray[idx]);


}

int da_append(darray *array, int value)
{
    if(array == NULL)
    {
        return 0;
    }

    array->thearray[array->size] = value;

    array->size = (array->size + 1);

    int *newarr = realloc(array->thearray, ((array->size * 10) * sizeof(int)));

    array->thearray = newarr;

    return 1;
}

void da_delete(darray *array)
{
    free(array);
}

size_t da_size(darray *array)
{
    return array->size;
}



int main()
{

}


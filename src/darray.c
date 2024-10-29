#include "/home/seth/Desktop/darray-assignmentSF-master/include/darray.h"
#include <stdlib.h>
#include <stdio.h>

struct darray
{
    int size;
    int thearray[];
};


darray *da_create()
{

    darray *dar = malloc(sizeof(darray));

    if(dar == NULL)
    {
        return NULL;
    }

    return dar;
    // darray dar = {0, {}};
    // darray dar1 = {0, {}, *dar};
    // return dar1.poi;

}

int *da_get(darray *array, size_t idx)
{
    // if(idx > (int)(sizeof(array->thearray) / sizeof(array->thearray[0])))
    // {
    //     return NULL;
    // }
    if(idx > da_size(array))
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
    array->size = (array->size + 1);

    darray *newdar = realloc(array, (100*sizeof(darray)+1));

    array = newdar;

    array->thearray[da_size(array)-1] = value;

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



// int main()
// {
//     darray* clobbah = da_create();
//     da_append(clobbah, 1);
//     da_append(clobbah, 2);
//     da_append(clobbah, 3);
//     da_append(clobbah, 4);
//     da_append(clobbah, 5);
//     da_append(clobbah, 6);
//     da_append(clobbah, 7);
//     int i;
//     for(i = 0; clobbah->thearray[i] != '\0'; i++)
//     {
//         printf("%d ", clobbah->thearray[i]);
//     }
//     printf("\n");
//     printf("%ls", da_get(clobbah, 4));
//
//
//     return 0;
// }


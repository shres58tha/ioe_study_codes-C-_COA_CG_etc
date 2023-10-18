Structure is a data type. You don't give values to a data type. You give values to instances/objects of data types.
So no this is not possible in C.

Instead you can write a function which does the initialization for structure instance.

Alternatively, You could do:

struct MyStruct_s 
{
    int id;
} MyStruct_default = {3};

typedef struct MyStruct_s MyStruct;
And then always initialize your new instances as:

MyStruct mInstance = MyStruct_default;
*************************************************

If you are using gcc you can give designated initializers in object creation.

typedef struct
{
   int id=0;
   char* name="none";
}employee;

employee e = 
{
 .id = 0;
 .name = "none";
};
Or , simply use like array initialization.

employee e = {0 , "none"};

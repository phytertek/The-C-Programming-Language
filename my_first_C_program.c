
#include <stdio.h>

int main(int argc, char **argv)
{
  printf("Hello world!");
  // forward declaration
  // It used to be required that any variable you wished to use inside of
  // a function had to be declared at the top of the function, then used later.
  // This has been relaxed post C99, but many developers and old C code still
  // follow it.
  int foo;
  // later
  foo = 5;
  // or, even more commonly:
  int i;
  for (i = 0; i < 5; ++i)
  {
  }
  // now it is allowed to do:
  int Foo = 5;

  // struct forward declaration
  // https://stackoverflow.com/questions/18658438/what-is-forward-declaration-and-the-difference-between-typedef-struct-x-and
  // automatically hoisted?
  struct element
  {
    int value;
    // Use of the forward declaration
    struct element *next;
  }; // Complete definition
  // Tagged struct, has to be defined as a struct to use
  struct flement
  {
    int value;
    // No need for a forward declaration here
    struct flement *next;
  } flement; // tag

  struct element bar;
  bar.value = 5;
  bar.next = &bar;

  struct flement baz;
  baz.value = 6;
  baz.next = &baz;

  typedef struct flement glement;
  glement bale;
  bale.value = 7;
  bale.next = &bale;

  /* faults - SIGSEGV, SIG, et
   * header files
   * file scope
   */
  // extern
  // C uses a technique called "file scope". The only objects and functions
  // that a C program is aware of are the ones that are located in the current
  // file. The extern keyword moves a variable from file scope into global scope
  // so it can be read by other files.
  extern int outsideVariable;
  // int y = outsideVariable;
  //Analysis
  // This program throws error in compilation. Because outsideVariable is declared
  // but not defined anywhere. Essentially, the variable isn’t allocated any memory.
  // And the program is trying to another variable to one that doesn’t exist at all.

  // includes
  // External files are referred to by their header.
  // Files that are included must be compiled into the final program by the
  // compiler - specifying the inclusion does not affect compiler behavior.
  // Adding the file to the compiler involves another step - either passing
  // the source file into the `gcc` command, or passing in the compiled `.o`
  // object file into the `gcc` command, or specifying the location of an
  // object file with the `-L` argument to gcc.
  // "" searches your current directory and directories passed in with -I
  // <> searches in system directories
  /* libraries
 * objects
 * compilation
 * compilation arguments
 * files within directories, linked and built
 * linking
 * printf formatting
 * comparisons && || !
 * bit shifting >> <<
 * binary operators &, |, ~
 * compiler optimizations

 clang -pedantic micro.C -S -o test.asm
 */
  char *myString = "Hello dude";
}

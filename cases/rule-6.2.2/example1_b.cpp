// BEGIN violation
extern long shared_counter;

long read_counter() {
    return shared_counter;
}
// END violation

// BEGIN violation
int clamp_byte(int v) {
    if (v < 0) {
        return 0;
    }
    return (v > 255) ? 255 : v;
}
// END violation

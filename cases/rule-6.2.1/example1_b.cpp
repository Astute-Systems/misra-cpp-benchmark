// BEGIN violation
struct Packet {
    int id;
    long length;
};

long packet_length() {
    Packet p{1, 2L};
    return p.length;
}
// END violation

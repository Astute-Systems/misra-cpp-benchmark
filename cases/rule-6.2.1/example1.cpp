// MISRA C++:2023 Rule 6.2.1 (Required)
// The one-definition rule shall not be violated
//
// Example 1: Two translation units define the same class differently

// BEGIN violation
struct Packet {
    int id;
    int length;
};

int packet_id() {
    Packet p{1, 2};
    return p.id;
}
// END violation

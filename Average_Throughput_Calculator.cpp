#include <iostream>
using namespace std;

// Function to calculate the average throughput (THP)
double calculate_average_throughput(int np, int packet_size, int time) {
    // Formula: Average THP = (NP * Packet Size * 8) / Time
    double throughput = (np * packet_size * 8.0) / time;
    return throughput;
}

// Function to calculate the reliability (for simplicity, assume 100% reliability)
double calculate_reliability(int np_sent, int np_received) {
    if (np_sent == 0) {
        return 0;  // Avoid division by zero
    }
    double reliability = (static_cast<double>(np_received) / np_sent) * 100;
    return reliability;
}

int main() {
    cout << "FANET Performance Metric Tool (Reliability & Average Throughput)" << endl;

    // Get user inputs for the simulation
    int np_sent, packet_size, time;
    cout << "Enter the number of packets sent:";
    cin >> np_sent;

    cout << "Enter the packet size (in bytes):";
    cin >> packet_size;

    cout << "Enter the time duration of transmission (in seconds): ";
    cin >> time;

    // Assuming that packets received is the same as packets sent (100% reliability)
    int np_received = np_sent;  // You can modify this if you have packet loss data

    // Calculate the average throughput
    double average_thp = calculate_average_throughput(np_sent, packet_size, time);

    // Calculate the reliability
    double reliability = calculate_reliability(np_sent, np_received);

    // Display the results
    cout << "\nPerformance Metrics:" << endl;
    cout << "Average Throughput (THP):" << average_thp << " bps" << endl;
    cout << "Reliability:" << reliability << "%" << endl;

    return 0;
}

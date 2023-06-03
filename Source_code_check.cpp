// Dev: Vu Nhat Quang, Nguyen Thanh Hung
// Date: 02/06/2023
// Complexity: O(n^2)
// Chương trình tô màu đồ thị bằng ý tưởng thuật toán DSaTur  
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <cstdlib>
using namespace std;
// Hàm sắp xếp bậc của đỉnh theo thứ tự từ lớn đến bé 
vector<int> sort_nodes_by_degree(const vector<vector<int>>& adj) {
    int n = adj.size();      // Số đỉnh trong mảng cạnh kề
    vector<pair<int, int>> node_degrees(n); 
    for (int i = 0; i < n; i++) {
        node_degrees[i] = {adj[i].size(), i}; // Mảng lưu giá trị số bậc của đỉnh và đỉnh xét
    }
    sort(node_degrees.rbegin(), node_degrees.rend()); // Sắp xếp mảng theo số bậc của đỉnh và đỉnh gốc sẽ chạy theo
    vector<int> sorted_nodes(n); 
    for (int i = 0; i < n; i++) {
        sorted_nodes[i] = node_degrees[i].second; // Mẩng sau khi được sắp xếp
    }
    return sorted_nodes;
}
// Function tìm độ bão hòa đỉnh, độ bão hòa đỉnh là số lượng đỉnh kề đã được tô màu
// max_degree là đỉnh có bậc lớn nhất
int saturation_degree(int node, const vector<int>& color, const vector<vector<int>>& adj, int max_degree) {
    vector<bool> neighbor_colors(max_degree, false); // Mảng đánh dấu đỉnh kề là chưa tô màu
    for (auto neighbor : adj[node]) { 
        if (color[neighbor] != -1) { // Nếu màu đã được tô (0, 1,.. tương đương màu 0, 1, 2,..)
            neighbor_colors[color[neighbor]] = true;  // Đánh dấu là đã được tô màu 
        }
    }
    int saturation = 0; 
    for (bool color : neighbor_colors) {
        if (color) { // Nếu màu được đánh dấu là tô
            saturation++; // Tăng độ bão hòa
        }
    }
    return saturation;
}
// Hàm tô màu 
vector<int> DSatTur(const vector<vector<int>>& adj) {
    int n = adj.size(); 
    vector<int> color(n, -1); // -1 là màu chưa được tô
    vector<int> sorted_nodes = sort_nodes_by_degree(adj); // Sắp xếp các bậc của đỉnh
    color[sorted_nodes[0]] = 0; // Gán màu đầu tiên cho đỉnh có bậc lớn nhất
//    int max_color = 0; // Số màu được sử dụng 
    int max_degree = 0; // Bậc lớn nhất
    for (const auto& neighbors : adj) {
        max_degree = max(max_degree, (int)neighbors.size()); 
        // Tìm bậc lớn nhất cho hàm saturation
    }

    for (int i = 1; i < n; i++) {
        int max_saturation = -1;
        int chosen_node = -1; // Màu được chọn để tô

        for (int j = 0; j < n; j++) { // Vòng duyệt tìm đỉnh có độ bão hòa lớn nhất
            int node = sorted_nodes[j];
            if (color[node] == -1) { // Nếu chưa được tô
                int saturation = saturation_degree(node, color, adj, max_degree); 
                if (saturation > max_saturation) {
                    max_saturation = saturation;
                    chosen_node = node;
                }
            }
        }

        vector<bool> used_colors(max_degree, false); // Mảng lưu các màu đã dùng 
        for (auto v : adj[chosen_node]) {
            if (color[v] != -1) {
                used_colors[color[v]] = true; //Nếu màu đã dùng thì đánh dấu 
            }
        }

        int j = 0;
        while (used_colors[j]) { // Vòng lặp tìm màu nhỏ nhất mà chưa được dùng
            j++;
        }
        color[chosen_node] = j; // Gán màu cho đỉnh tìm được cho màu nhỏ nhất trên
    //    max_color = max(max_color, j); // Hàm tìm số màu đã dùng
    }
    
    return color;
}

int main()
{

    vector<int> testcase = {20,50,70,100,250,500,1000};
    vector<int> testcase2 = {1,3,5,7,9};
    for (auto value : testcase)
    {
        for (auto value2 : testcase2)
        {

            string str_value = to_string(value);
            string str_value2 = to_string(value2);
            string input = "gc_" + str_value + "_" + str_value2 + ".txt";
            string output = "gc_" + str_value + "_" + str_value2 + "tomau.txt" ;
            string check_valid = "\".\\check_valid_coloring " + input + " " + output + "\"";
    ofstream output_file(output); //FILE in ra
    ifstream input_file(input);  //FILE lấy dữ liệu
    int n, m; //n là số đỉnh, m là số cạnh
    input_file >> n >> m;
    clock_t start_time = clock(); // Đếm thời gian chạy chương trình

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        input_file >> u >> v;
        adj[u-1].push_back(v-1); // Phải gán -1 do đồ thị đề bài bắt đầu từ 1 
        adj[v-1].push_back(u-1);
    }

    vector<int> color = DSatTur(adj);  // Mảng lưu màu tô
    int max_color = *max_element(color.begin(), color.end());  // Màu đã dùng

    output_file << max_color + 1 << endl;
    for (int i = 0; i < n; i++)
    {
        output_file << color[i] + 1 << endl;
    }
    input_file.close();
    output_file.close();
    clock_t end_time = clock();
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC; // Tính toán thời gian chương trình
    cout << "Elapsed time: " << elapsed_time << " seconds" << endl;
    system(check_valid.c_str()); // Hàm check luôn chương trình xem màu tô có đúng không ?
        }
    }
    return 0;
}
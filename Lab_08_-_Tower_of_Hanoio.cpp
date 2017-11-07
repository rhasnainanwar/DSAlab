#include <iostream>
#include <stack>

void moveDisk(std::stack<int>&, std::stack<int>&);
void move_hanoi(int, std::stack<int>&, std::stack<int>&, std::stack<int>&);
int count = 0;
int main(){
    std::stack<int> tower1;
    std::stack<int> tower2;
    std::stack<int> tower3;

    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    std::cout << "\n\tTower # 1: " << &tower1;
    std::cout << "\n\tTower # 2: " << &tower2;
    std::cout << "\n\tTower # 3: " << &tower3 << "\n" << std::endl;

    for(int i = n; i > 0; i--)
        tower1.push(i);

    move_hanoi(n, tower1, tower3, tower2);

    std::cout << "\nMoves: " << count << std::endl;
    return 0;
}

void move_hanoi(int n, std::stack<int>& src, std::stack<int>& dest, std::stack<int>& spare){
    if(n == 1)
        moveDisk(src, dest);
    else {
        move_hanoi(n - 1, src, spare, dest);
        moveDisk(src, dest);
        move_hanoi(n - 1, spare, dest, src);
    }
}

void moveDisk(std::stack<int>& src, std::stack<int>& dest){
    int val = src.top();
    src.pop();
    dest.push(val);
    std::cout << "Moving disk " << val << "\t ( " << &src << " -> " << &dest << " )" << std::endl;
    count++;
}

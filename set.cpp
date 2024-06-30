#include<iostream>
#include<vector>
using namespace std;

//new data structure
class SET{
public:
    vector<int> data;

    //constructor called
    SET(vector<int> data={}){
        this->data=data;
    }

    //sorting
    void quick_Sort(int l, int r) {
        if (l >= r){
            return;
        }
        int p = part(l, r);
        quick_Sort(l, p - 1);
        quick_Sort(p + 1, r);
    }

    int part(int l, int r) {
        int p_value = data[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (data[j] <= p_value) {
                i++;
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        int temp = data[i + 1];
        data[i + 1] = data[r];
        data[r] = temp;
        return i + 1;
    }

    //checking presence of element
    bool presentIn(int x) const {
        for (int i : this-> data){
            if(i==x){
                return true;
            }
        }
        return false;
    }
    //Insertion function
    void Insert(int data){ 
        if(!presentIn(data)){
            this-> data.push_back(data);
        }   
    }

    //Deletion function
    int Delete(int data){
        if(!presentIn(data)){
            return this->data.size();
        }
        else{
            for(int i = 0;i < this->data.size();i++){
                if(this->data[i]==data){
                this->data.erase(this->data.begin()+i);
                break;
                }
            }
            return this->data.size();
        } 
    }

    //belongsto function
    int belongsto(int data){ 
        int s = (this->data).size();
        int ans = 0;
        for(int i = 0; i<s; i++){
            if(this->data[i]==data){
                ans = 1;
                break;
            }   
        }
        return ans;

    }

    //size function
    int size(){
        return this->data.size();
    }

    //union function
    void Union(const SET& set2) {
        for(int i : set2.data){
            Insert(i);
        }
    }

    //intersection function
    void Intersection(const SET& set2){
        vector<int> final;
        for(int i : data){
            if(set2.presentIn(i)){
                final.push_back(i);
            }
        }
        data = final;
    }
    
    //difference function
    void Difference(const SET& set2) {
        vector<int> final;
        for(int i : data){
            if(!set2.presentIn(i)){
                final.push_back(i);
            }
        }
        data = final;
    }

    //symmetricdifference function
    void SymmetricDifference(const SET& set2) {
        vector<int> final;
        for(int i : data){
            if(!set2.presentIn(i)){
                final.push_back(i);
            }
        }
        for(int i : set2.data){
            if(!presentIn(i)){
                final.push_back(i);
            }
        }
        data = final;
    }

    //print function
    void Print() {
        if (!data.empty()) {
            for (int i = 0; i < data.size() - 1; i++) {
                cout << data[i] << ",";
            }
            cout << data.back();
        }
        cout << endl;
    }
};


int main(){
    vector<SET> sets;
    //test cases
    
    int comm_no, set_no, data;
    while (cin >> comm_no) {
        if (comm_no == 1) {
            cin >> set_no >> data;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            sets[set_no].Insert(data);
            sets[set_no].quick_Sort(0, sets[set_no].size() - 1);
            cout << sets[set_no].size() << endl;
        } 
        else if (comm_no == 2) {
            cin >> set_no >> data;
            if(set_no>=(sets.size())){
                cout<<-1<<endl;
            }
            else{
            cout<<sets[set_no].Delete(data)<<endl;
            }
            } 
        else if (comm_no == 3) {
            cin >> set_no >> data;
            if(set_no>=(sets.size())){
                cout<<-1<<endl;
            }
            else{
            cout << sets[set_no].belongsto(data) << endl;
        }
        }
        else if (comm_no == 4) {
            int set_num2;
            cin >> set_no >> set_num2;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            if(set_num2>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            sets[set_no].Union(sets[set_num2]);
            sets[set_no].quick_Sort(0, sets[set_no].size() - 1);
            cout<<sets[set_no].size()<<endl;
            } 
        else if (comm_no == 5) {
            int set_num2;
            cin >> set_no >> set_num2;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            if(set_num2>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            sets[set_no].Intersection(sets[set_num2]);
            sets[set_no].quick_Sort(0, sets[set_no].size() - 1);
            cout<<sets[set_no].size()<<endl;
        } 
        else if (comm_no == 6) {
            cin >> set_no;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            cout << sets[set_no].size() << endl;
        } 
        else if (comm_no == 7) {
            int set_num2;
            cin >> set_no >> set_num2;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            if(set_num2>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            sets[set_no].Difference(sets[set_num2]);
            sets[set_no].quick_Sort(0, sets[set_no].size() - 1);
            cout << sets[set_no].size() << endl;
        }
        else if (comm_no == 8) {
            int set_num2;
            cin >> set_no >> set_num2;
            if(set_no>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            if(set_num2>=(sets.size())){
                SET data;
                sets.push_back(data);
            }
            sets[set_no].SymmetricDifference(sets[set_num2]);
            sets[set_no].quick_Sort(0, sets[set_no].size() - 1);
            cout << sets[set_no].size() << endl;
        } 
        else if (comm_no == 9) {
            cin >> set_no;
            if(set_no>=(sets.size())){
                cout<<endl;
            }
            else{
            sets[set_no].Print();
            }
        }
    }
    return 0;
}

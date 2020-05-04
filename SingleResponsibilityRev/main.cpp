#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>


struct  Journal{
    std::string title_m;
    std::vector<std::string> entries_m;
    //constructor
    Journal(const std::string &title):
        title_m(title){}
        //functions
        void add_entry(const std::string& entry){
            static int count = 1;
            entries_m.push_back(std::to_string(count) + " " + entry);
        }
};

struct PersistenceManager{ 
    PersistenceManager() = default;
    static void save(const Journal& J, const std::string& filename)
    {
        std::ofstream ofs(filename);
        for(auto& e : J.entries_m){
            ofs << e << "\n";
        }
    }
};

int main(){
    std::cout << "Hello world\n";
    Journal journal("4th May");
    journal.add_entry(" Trial ");
    PersistenceManager pm;
    pm.save(journal, "Saving2");
    
    return 0;
}

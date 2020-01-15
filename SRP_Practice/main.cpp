#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>




class Journal{
	friend class PersistenceManager;
	private:
		std::string title_;
		std::vector<std::string> entries_;
	public:
		Journal(const std::string& title) : title_(title){}
		
		void addEntry(const std::string& entry){
			static int numEntries{1};
			entries_.push_back(std::to_string(numEntries++) + " " + entry);
		}
		

};

class PersistenceManager{
	public:	
		static void save(const Journal& journal, const std::string& filename){
		std::ofstream ofs(filename);			
		for(auto entry : journal.entries_)
			ofs << entry << "\n";    
		}
};

int main(){
	Journal MyDiary("8 January");
	MyDiary.addEntry(" Learnt Cpp");
	MyDiary.addEntry(" worked on vbf");
	MyDiary.addEntry(" I LOVE YOU GG")
	PersistenceManager::save(MyDiary, "PersonalFile");

}


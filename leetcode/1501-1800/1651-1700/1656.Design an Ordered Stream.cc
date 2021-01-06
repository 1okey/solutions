// https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream {
private:
    int idx = 0;
    vector<string> stream;
public:
    OrderedStream(int n) {
        stream.resize(n);
    }
    
    vector<string> insert(int id, string value) {
        id -= 1;
        stream[id] = value;
        vector<string> chunk;

        if(id == idx){
            while(id < stream.size() && stream[id] != ""){
                chunk.push_back(stream[id]);
                id++;
                idx++;
            }
        }

        return chunk;
    }
};
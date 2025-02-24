class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, read = 0;
        int n = chars.size();
        
        while (read < n) {
            char current = chars[read];
            int count = 0;
            
            
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }
            
         
            chars[write++] = current;
            
           
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};

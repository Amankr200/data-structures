class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Find how many words can fit into this line
            while (last < n && totalChars + 1 + words[last].length() <= maxWidth) {
                totalChars += 1 + words[last].length();
                last++;
            }

            string line;
            int numWords = last - index;
            int numSpaces = maxWidth - totalChars + (numWords - 1);

            // If last line OR only one word → left-justified
            if (last == n || numWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                while (line.length() < maxWidth) line += " ";
            } 
            // Otherwise → fully justify
            else {
                int totalWordLen = 0;
                for (int i = index; i < last; i++) totalWordLen += words[i].length();
                int totalSpaces = maxWidth - totalWordLen;
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spacesToAdd = spaceBetween + (i - index < extraSpaces ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};


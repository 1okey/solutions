// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

int designerPdfViewer(vector<int> h, string word) {
    int max_h = h[word[0]];
    for(char c: word) {
        max_h = max(max_h, h[c - 0x61]);
    }
    
    return max_h * word.size();
}
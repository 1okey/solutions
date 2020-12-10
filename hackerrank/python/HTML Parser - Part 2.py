# https://www.hackerrank.com/challenges/html-parser-part-2/problem

from html.parser import HTMLParser
class ProxyHTMLParser(HTMLParser):
    # def handle_starttag(self, tag, attrs):        
    #     print ('Start :',tag)
    #     for ele in attrs:
    #         print ('->',ele[0],'>',ele[1])
            
    # def handle_endtag(self, tag):
    #     print ('End   :',tag)
        
    # def handle_startendtag(self, tag, attrs):
    #     print ('Empty :',tag)
    #     for ele in attrs:
    #         print ('->',ele[0],'>',ele[1])
    
    def handle_comment(self, data):
        print(">>>", "Single-line" if '\n' not in data else "Multi-line", "Comment", sep=' ')
        print(data, sep='\n')

    def handle_data(self, data):
        if data.strip():
            print(">>> Data")
            print(data, sep='\n')
            
parser = ProxyHTMLParser()
parser.feed('\n'.join([input().strip() for _ in range(int(input()))]))
parser.close()

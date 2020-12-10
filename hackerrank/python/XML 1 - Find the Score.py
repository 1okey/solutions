# https://www.hackerrank.com/challenges/xml-1-find-the-score/problem

def get_attr_number(node):
    count = 0
    nodes = [node]
    for el in nodes:
        nodes += list(el)
        count += len(el.attrib)

    return count


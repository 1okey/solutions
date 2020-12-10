# https://www.hackerrank.com/challenges/validate-list-of-email-address-with-filter/problem

def fun(s):
    try:
        user, domain = s.split('@')
        site, ext = domain.split('.')
        user = ''.join([c for c in user if c != '_' and c != '-'])
    except:
        return False;

    return len(ext) < 4 and site.isalnum() and ext.isalpha() and user.isalnum()

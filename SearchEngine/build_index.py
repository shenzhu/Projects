def add_to_index(index, keyword, url):
    if keyword in index:
        index[keyword].append(url)
    else:
        index[keyword] = [url]

def add_page_to_index(index, url, content):
    #get the keywords in the web page
    words = content.split()

    for word in words:
        add_to_index(index, word, url)

def lookup(index, keyword):
    if keyword in index:
        #returns a list of urls
        return index[keyword]
    else:
        #if the keyword is not in the index, return None
        return None

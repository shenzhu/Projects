from buidl_index import add_page_to_index

#get the content of web page
def get_page(url):
    try:
        import urllib
        return urllib.urlopen(url).read()
    except:
        return ""

#get the next hyperlink in the page and stores the end position of the former hyperlink
def get_next_target(page):
    start_link = page.find('<a href=')

    #if can not find any hyperlink, return value of find is -1
    if start_link == -1:
        return None, 0

    #the second argument of find is the start position of find(included)
    start_quote = page.find('"', start_link)
    end_quote = page.find('"', start_quote + 1)

    url = page[start_quote + 1:end_quote]

    return url, end_quote


#get all the links in a web page
def get_all_links(page):
    links = []
    while True:
        url, endpos = get_next_target(page)

        #check if the url is valid, if so, add it to the 'links' list
        if url:
            links.append(url)
            page = page[endpos:]
        #can not find anymore hyper linke in the web page
        else:
            break

    return links

#union two lists into one
def union(a, b):
    for item in b:
        if item not in a:
            a.append(item)


#return index, graph of inlinks
#graph page(url):outlinks(list)
#index keyword:url(list)
#argument depth controls the depth of crawling web, its default value is 10
def crawl_web(seed, depth = 10):
    tocrawl = [seed]
    crawled = []
    graph = {}
    index = {}

    while tocrawl and depth > 1:
        #get a page to crawl from tocrwal
        page = tocrawl.pop()

        #make sure that there no the same pages in graph
        if page not in crawled:
            content = get_page(page)
            #if the page has not been crawled, add the page into index and find the links to crawl in the page
            add_page_to_index(index, page, content)

            #get all the links from the current page
            outlinks = get_all_links(content)

            #maintain a dict mapping page to its outlinks
            graph[page] = outlinks
            #add the links from the current page to tocrawl
            union(tocrawl, outlinks)

            crawled.append(page)    

        depth = depth - 1    
    #return two dicts
    return index, graph
            

            
        
    

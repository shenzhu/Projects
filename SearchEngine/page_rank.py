def compute_ranks(graph):
    d = 0.8 #damping factor
    numloops = 10 #set the number of loop to 10

    #a dict mapping page to its value
    ranks = {}
    npages = len(graph)

    #give every page a initial value
    for page in graph:
        ranks[page] = 1.0 / npages

    for item in range(0, numloops):
        newranks = {}

        #iterate to give new values to every page
        for page in graph:
            newrank = (1 - d) / npages

            
            for node in graph:
                if page in graph[node]:
                    newrank = newrank + d * (ranks[node] / len(graph[node]))
            
            newranks[page] = newrank
        ranks = newranks

    return ranks

#use quick sort algorithm to sort searched urls according to their values
def quick_sort(url_list, ranks):
    url_left = [] #stores the url whose value is smaller than the pivot
    url_right = [] #stores the url whose value is larger than the pivot

    if len(url_list) <= 1:
        return url_list

    #choose the first item in the url_list as the pivot for quick sort
    pivot = url_list[0]

    for url in url_list[1:]:
        if ranks[url] <= ranks[pivot]:
            url_left.append(url)
        else:
            url_right.append(url)

    return quick_sort(url_left, ranks) + [pivot] + quick_sort(url_right, ranks)

def ordered_search(index, ranks, keyword):
    if keyword in index:
        urls = index[keyword]
    else:
        return None

    return quick_sort(urls, ranks)

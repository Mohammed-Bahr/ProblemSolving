from collections import defaultdict


class Solution:
    def DFS(self, adj_list, current, itinerary):

        while adj_list[current]:
            # smallest lexical destination
            next_city = adj_list[current][0]

            # remove only one occurrence
            adj_list[current].pop(0)

            self.DFS(adj_list, next_city, itinerary)

        itinerary.append(current)

    def findItinerary(self, tickets):

        adj_list = defaultdict(list)

        # build graph
        for src, dst in tickets:
            adj_list[src].append(dst)

        # keep lexical order like multiset
        for city in adj_list:
            adj_list[city].sort()

        itinerary = []

        self.DFS(adj_list, "JFK", itinerary)

        itinerary.reverse()

        return itinerary


if __name__ == "__main__":
    sol = Solution()

    tickets = [
        ["JFK", "SFO"],
        ["JFK", "ATL"],
        ["SFO", "ATL"],
        ["ATL", "JFK"],
        ["ATL", "SFO"],
    ]

    itinerary = sol.findItinerary(tickets)

    print(itinerary)

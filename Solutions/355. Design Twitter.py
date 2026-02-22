from collections import defaultdict
import heapq

class Twitter(object):

    def __init__(self):
        self.time = 0
        self.followMap = defaultdict(set)
        self.tweetsMap = defaultdict(list)

    def postTweet(self, userId, tweetId):
        self.tweetsMap[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId):
        minHeap = []

        users = self.followMap[userId] | {userId}

        for u in users:
            for time, tweetId in self.tweetsMap[u][-10:]:
                heapq.heappush(minHeap, (time, tweetId))
                if len(minHeap) > 10:
                    heapq.heappop(minHeap)

        # extract tweets sorted by most recent
        result = []
        while minHeap:
            result.append(heapq.heappop(minHeap)[1])

        return result[::-1]

    def follow(self, followerId, followeeId):
        if followerId != followeeId:
            self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        self.followMap[followerId].discard(followeeId)
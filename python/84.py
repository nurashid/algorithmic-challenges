def largestRectangleArea(self, hist):
    s = [-1]
    marea = 0
    if len(hist) == 1:
        return hist[0]
    for i, v in enumerate(hist):
        while s[-1] != -1 and hist[s[-1]] >= v:
            marea = max(marea, hist[s[-1]]*(i - s[-2] - 1));
            s.pop()
        s.append(i)

    while s[-1] != -1:
        marea = max(marea, hist[s[-1]] * (len(hist) - s[-2] -1));
        s.pop()

    return marea

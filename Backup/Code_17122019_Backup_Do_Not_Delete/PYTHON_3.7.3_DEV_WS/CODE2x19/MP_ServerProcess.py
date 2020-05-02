import multiprocessing


def func(d, l):
    d[14] = '14'
    d[20] = '20'
    d[24] = '24'
    d['e'] = '11.03'
    d['m'] = '16.11'
    l.reverse()


if __name__ == '__main__':
    with multiprocessing.Manager() as manager:
        d = manager.dict()
        l = manager.list(range(20))

        p = multiprocessing.Process(target=func, args=(d, l))

        p.start()
        p.join()

        print(d)
        print(l)

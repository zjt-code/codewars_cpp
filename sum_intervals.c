#include<stdio.h>
#include<stdbool.h>

struct interval {
    int first;
    int second;
};


bool is_overlap(const struct interval *a, const struct interval *b)
{

        return !((a->second<b->first)||(b->second < a->first));
}

int sum_intervals(const struct interval *v, size_t n)
{
    struct interval max_range=*v;

    for( size_t x=0; x<(n-1); x++)
    {
        for(size_t y=x+1; y< n; y++)
        {
               if(is_overlap(v+x, v+y));                

        }

    }
    return 0;
}

const struct interval interval_array[]=
{
    {1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}
};

int main()
{

    sum_intervals(interval_array, sizeof(interval_array)/sizeof(struct interval));

 return 0;
}
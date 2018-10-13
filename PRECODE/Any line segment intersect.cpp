//PSEUDOCODE///use self balancing trees of some sort to insert , delete, check immediately top and immediately below elements
///True / False
/*sweepLineIntersection(Points[0..2n-1]):
1. Sort Points[] from left to right (according to x coordinate)

2. Create an empty Self-Balancing BST T. It will contain all active line
   Segments ordered by y coordinate.

// Process all 2n points
3. for i = 0 to 2n-1

    // If this point is left end of its line
    if (Points[i].isLeft)
       T.insert(Points[i].line())  // Insert into the tree

       // Check if this points intersects with its predecessor and successor
       if ( doIntersect(Points[i].line(), T.pred(Points[i].line()) )
         return true
       if ( doIntersect(Points[i].line(), T.succ(Points[i].line()) )
         return true

    else  // If it's a right end of its line
       // Check if its predecessor and successor intersect with each other
       if ( doIntersect(T.pred(Points[i].line(), T.succ(Points[i].line()))
         return true
       T.delete(Points[i].line())  // Delete from tree

4. return False
*/

///ONLY HORIZONTAL AND VERTICAL LINES
//we won't consider coincident endpoints to intersect.
#define x second
#define y first
typedef pair<int,int >point;
struct event
{
    point p1,p2;
    int type;
    event() {};
    event(point p1,point p2, int type) : p1(p1), p2(p2),type(type) {};  //initialization of event
};
int n,e;
event events[MAX];
bool compare(event a, event b)
{
    return a.p1.x<b.p1.x;
}
set<point>s;
void hv_intersection()
{
    for (int i=0; i<e; ++i)
    {
        event c = events[i];
        if (c.type==0)
            s.insert(c.p1);//insert starting point of line segment into set
        else if (c.type==1)
            s.erase(c.p2);//remove starting point of line segment from set, equivalent to removing line segment
        else
        {
            for (typeof(s.begin()) it=s.lower_bound(make_pair(c.p1.y,-1)); it!=s.end() && it->y<=c.p2.y; it++) // Range search
                printf("%d, %d\n", events[i].p1.x, it->y);//intersections
        }
    }
}
int main ()
{
    scanf("%d", &n);
    int p1x,p1y,p2x,p2y;
    for (int i=0; i<n; ++i)
    {
        scanf("%d %d %d %d", &p1x, &p1y,&p2x, &p2y);
        if(p1x==p2x)//if vertical line, one event with type=2
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else//if horizontal line, two events one for starting point and one for ending point
        {
            //store both starting points and ending points
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            //store both ending and starting points, note the order in the second,
            //this is because we sort on p1, so ending points first, then we remove a line when we hit its ending point ,
            //so we need its starting point for removal of line
            events[e++]=event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
    }
    sort(events, events+e,compare);//on x coordinate
    hv_intersection();
    return 0;
}


///ANY TYPE OF LINE Printing all intersections
/*
First, let us list down the assumptions in the algorithm:
1. There are no vertical segments.
2. No two segments intersect at their endpoints.
3. No three (or more) segments have a common intersection.
4. All endpoints of the segments and all intersection points have different x-coordinates.
5. No two segments overlap.
*/
/*
Events: end points of line segments, intersection points.(We will insert the intersection point as we find them).
Here, we would use priority queue as our data structure as presort wouldn't work because of dynamic insertion and deletion of intersection points.
Let us denote the priority queue by PQ
*/
/**
PSEUDOCODE
Initialize PQ = all segment endpoints;
    Initialize SL to be empty;
    Initialize output intersection list IL to be empty;

    While (PQ is nonempty) {
        Let E = the next event from PQ;
        If (E is a left endpoint) {
            Let segE = segment of E;
            Add segE to SL;
            Let segA = the segment Above segE in SL;
            Let segB = the segment Below segE in SL;
            If (I = Intersect( segB with segA) exists)
                Delete I from PQ;
            If (I = Intersect( segE with segA) exists)
                Insert I into PQ;
            If (I = Intersect( segE with segB) exists)
                Insert I into PQ;
        }
        Else If (E is a right endpoint) {
            Let segE = segment of E;
            Let segA = the segment Above segE in SL;
            Let segB = the segment Below segE in SL;
            Delete segE from SL;
            If (I = Intersect( segA with segB) exists)
                    Insert I into PQ;
        }
        Else {  // E is an intersection event
            Add intersect point of E to the output list IL;
            Let segE1 above segE2 be intersecting segments of E in SL;
            Swap their positions so that segE2 is now above segE1;
            Let segA = the segment above segE2 in SL;
            Let segB = the segment below segE1 in SL;
            If (I = Intersect( segE1 with segA) exists)
                Delete I from PQ;
            If (I = Intersect( segE2 with segB) exists)
                Delete I from PQ;
            If (I = Intersect(segE2 with segA) exists)
                    Insert I into PQ;
            If (I = Intersect(segE1 with segB) exists)
                    Insert I into PQ;
        }
        remove E from PQ;
    }
    return IL;
**/

/*
On a conclusive note of this tutorial , I would like to discuss one more problem, that is ,
finding if any two line segments intersect in given N line segments. The same algorithm we applied above can be used with some changes as:
1. We won't consider any intersection event, that means we can presort instead of using PQ.
2. When we encounter any intersection , we return true.
That was line sweep's one more application. Now,try on the attached problem.
*/

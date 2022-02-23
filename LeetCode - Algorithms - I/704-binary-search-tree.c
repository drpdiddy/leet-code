int search(int* arr, int n, int target){

    int lower_bound = 0;
    int upper_bound = n;

    /*n=0*/
    /*n=1, lower_bound=0, upper_bound=1, middle=0*/
    /*n=2, lower_bound=0, upper_bound=2, middle=0*/
    /*n=3, target=0, lower_bound=0, upper_bound=3, middle=1*/
    /*n=3, lower_bound=0, upper_bound=1, middle=0*/

    while (lower_bound < upper_bound) {

        int middle = -1;

        if ((upper_bound - lower_bound) % 2 == 0)
            middle += lower_bound + (upper_bound-lower_bound)/2;
        else
            middle += lower_bound + (upper_bound-lower_bound + 1)/2;

        if (arr[middle] < target)
            lower_bound = middle + 1;
        else if (arr[middle] > target)
            upper_bound = middle;
        else
            return middle;

    }

    return -1;

}
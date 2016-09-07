#include "../lib/second_frequent.h"
using namespace std;

//Usage: after running make, run with ./secondFrequent
int main(int argc,char ** argv){
  if(argc != 2){
    exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
  }
   //First we parse the file into an integer array. File opperations handled here
   unsigned int * array = parseFile(argv[1]);
   unsigned int len = array[0];

   // Next, sort the array in O(nlogn) so we can do an O(n) scan later
   mergeSort(array, 1, len);

   // Calculate second most frequent be scanning
   unsigned int element = secondFrequent(&array[1], len);

   cout << element << endl;
   free(array);
   return 0;
}

// Handle file opperation, parsing, and transfer to array
unsigned int * parseFile(char * filename){
   // open file from args and verify intact.
   ifstream infile;
   infile.open(filename);
   if (!infile.is_open()){
      exit(FILE_FAILED_TO_OPEN);
   }

   //Initialize intiger array of size of file. Scan for num lines first.
   unsigned int line_count = 0;
   string line;
   while(getline(infile, line)){
      //Parse each line of input for format. Note: no instructions given for empty lines but treated as errors
      if(checkLine(line) && !line.empty()){
         line_count++;
      }else{
         exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
      }
   }

   if(line_count == 0)
      exit(PARSING_ERROR_EMPTY_FILE);

   infile.clear();
   infile.seekg(0);

   unsigned int * array = (unsigned int *) malloc(sizeof(unsigned int) * line_count + 1);
   if (array == nullptr) {
      return NULL; // No instructions for handling this error case.
   }
   array[0] = line_count;
   int index = 1;

   while (getline (infile,line)){
      array[index++] = stoi(line);
    }
   //Close input file and verify success.
   infile.close();
   if (infile.is_open()){
      exit(FILE_FAILED_TO_CLOSE);
   }
   return array;
}

//insure each line of input matches character constraints (is only non-neg int)
int checkLine(string str){
   int i = 0;
   while(str[i] != '\0'){
      if (!isdigit(str[i])){
         return 0;
      }
      i++;
   }
   return 1;
}

// Main logic below. Iterate through sorted array and track most frequent, second most frequent
unsigned int secondFrequent(unsigned int * array, unsigned int len){
   unsigned int first_popular = array[0], first_cnt = 1;
   unsigned int second_popular = 0, second_cnt = 0;
   unsigned int prev = array[0], tmp_count = 1;

   // Initialize most popular as first and track count
   unsigned int i = 1;
   while(array[i] == prev){
      i++;
   }

   first_cnt = i;
   prev = array[i];

   //All same element
   if (first_cnt == len)
      return 0;

   for(i = first_cnt + 1; i < len; i++){

      // Scan array for alike elements and store in temp
      if(array[i] == prev){
         tmp_count++;
      }else{

         //If more frequent element set found, update first & second most frequent
         if(tmp_count > first_cnt){
            second_cnt = first_cnt;
            second_popular = first_popular;

            first_cnt = tmp_count;
            first_popular = array[i - 1];
         }
         //Update first most frequent to higher val
         else if(tmp_count == first_cnt){
            first_popular = array[i - 1];
         }

         else if(tmp_count > second_cnt){
            second_cnt = tmp_count;
            second_popular = array[i - 1];
         }

         //Update second most frequent to higher val
         else if(tmp_count == second_cnt){
            second_popular = array[i - 1];
         }
         prev = array[i];
         tmp_count = 1;
      }
   }
   //Run same checks as previous on final element group
   if(tmp_count > first_cnt){
      second_cnt = first_cnt;
      second_popular = first_popular;

      first_cnt = tmp_count;
      first_popular = array[i - 1];
   }
   else if(tmp_count == first_cnt){
      first_popular = array[i - 1];
   }
   else if(tmp_count > second_cnt){
      second_cnt = tmp_count;
      second_popular = array[i - 1];
   }
   else if(tmp_count == second_cnt){
      second_popular = array[i - 1];
   }

   return (second_cnt == 0) ? 0 : second_popular;
}

// Recursively sort intiger array by diving into sub-arrays and merging in sorted order.
void mergeSort(unsigned int * arr, unsigned int low, unsigned int high){
   if(low < high){
      unsigned int mid = (low + high) / 2;
      mergeSort(arr, low, mid);
      mergeSort(arr, mid + 1, high);

      merge(arr, low, high, mid);
   }
   return;
}

// Standard merge function. Merge arrays in sorted order.
void merge(unsigned int arr[], unsigned int low, unsigned int high, unsigned int mid){
   unsigned int i, j, k;
   unsigned int * c = (unsigned int *)malloc(sizeof(unsigned int) * high + 1);

   i = k = low;
   j = mid + 1;
   while (i <= mid && j <= high){
      if(arr[i] <= arr[j]){
         c[k] = arr[i];
      i++;
   }
   else{
      c[k] = arr[j];
      j++;
   }
   k++;
   }
   while(i <= mid){
      c[k] = arr[i];
      k++;
      i++;
   }
   while(j <= high){
      c[k] = arr[j];
      j++;
      k++;
   }
   for(i = low ; i <= high; i++){
      arr[i] = c[i];
   }
   free(c);
   return;
}

void enshu_3_6(double mat1[10][10], double mat2[10][10],double res[10][10]){
    int i=0;
    int j=0;
    while(i<10){
        while(j<10){
           res[i][j] =mat1[i][j]+mat2[i][j];
            j++;
        }
        j=0;
        i++;

    }
}

int main(){
    return 0;
}
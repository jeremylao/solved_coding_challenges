import java.util.Scanner;
import java.io.File;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.io.BufferedInputStream;


public class max_prod{
	
	
	public static BigInteger test_function(int test){
		test = test + 1000;
		return BigInteger.valueOf(test);
	}
	
	public static BigInteger[] best(int start, int end, BigInteger[] input_array, BigInteger[] lookup){
		BigInteger temp; //= lookup[start];
		//cout << "This is start: " << start << endl;
		//cout << "This is end: " << end << endl;
	
		temp = BigInteger.valueOf(1);
	
		for(int j = 0; j < end; ++j){
			//cout << "outer j : " << j << endl;
			for(int z = end; z>j; --z){
				//cout << " inner " << endl;
				temp = BigInteger.valueOf(1);
				for(int i = j; i<z; ++i){
					temp = temp.multiply(input_array[i]);
					//cout << "Temp: " << temp << " output array " << input_array[i] << endl;
				}
		
				lookup[j] = lookup[j].max(temp);
				//cout << "this is max: " << lookup[j] << endl;
			}
		}
		return lookup;
	}

	public static void main(String[] args) throws IOException{
		
		BigInteger[] input_array = new BigInteger[1000000];
		BigInteger[] lookup = new BigInteger[1000000];
		BigInteger[] clean_input_array = new BigInteger[100];
		BigInteger sentinel = BigInteger.valueOf(-999999);
		
	
		
		Scanner sc = new Scanner(System.in);
		int idx = 0; int run = 0;
		
		while(sc.hasNextLine()){
			
			Scanner in_line = new Scanner(sc.nextLine());
			int temp = 0;
			
			if(!in_line.hasNext()){
				break;
			}
			
			while(in_line.hasNextInt()){
				temp = in_line.nextInt();
				
				if(temp == -999999){
					input_array[idx] = BigInteger.valueOf(temp);
					++idx;
					++run;
				}
				else{
					input_array[idx] = BigInteger.valueOf(temp);
					++idx;
				}
			}
			
			
		}
		int k = 0;
		for (int a = 0; a<run; ++a){
			
			for(int i = 0; i<100000; ++i){
				lookup[i] = BigInteger.valueOf(-8888888);
			}
			
			int clean_index = 0;
			int j = 0; 
			while(true){
				if(input_array[k].equals(sentinel)){
					break;
				}
				//System.out.println(input_array[k]);
				clean_input_array[j] = input_array[k];
				++k; ++j;
			}
			
			++k;
		//for(int b = 0; b<j; ++b){
		//	System.out.println(clean_input_array[b]);
		//}
		
		lookup = best(0, j, clean_input_array, lookup);
		BigInteger result = BigInteger.valueOf(-9999999);
		
		for(int i = 0 ; i<j; ++i){
			
			if(lookup[i].compareTo(result) ==1){
				result = lookup[i];
			}

		}
		System.out.println(result);
		
		for(int c = 0; c<100; ++c){
			clean_input_array[c] = BigInteger.valueOf(0);
		}
		}
	}
		
}
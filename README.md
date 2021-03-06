<HTML>
<p>This is the solution of the programming contest Google HashCode 2020 Online Qualification Round.</p>
<p>The problem statement is in the PDF attached. Go through it before reading the solution implemented by us.</p> 
<p> The solution implemented by us(in C++) gave a score of 26.5 million in the Extended Round(for reference, the best score was 27.2 million) </p>
<p> Most of this code was written during the Round, but the main logic portion was written during Extended Round(which was just for fun and lasted 16 days) </p>
<h2> Solution Implemented by Us: </h2>
<ol>
<li>The code is designed only to read one library file. So you will have to recompile the file six times(for a total of six input files). Just change the input and output file name. It is at the starting of the code as a preprocessor directive. </li>
<li>The code reads all book data and stored it in an array of structure of books. </li>
<li>The code then reads all the libraries and stored the information in an array of class library.</li>
<li>Class library then uses sort and score methods to get the scores of each library.</li>
<li>The library with the best score is selected and its id(location in array) is stored in an array called libord(which stores the order in which libraries are signed up).</li>
<li>The scores of the book which will be scanned from the first library are set to zero(using dupkill function in class library).</li>
<li>Then the sort function of all the left libraries is called again(which now omits already scanned books). Then the score of the libraries is calculated again. The libraries are scored as follows:</li>
<ol>
<li>The books present in the library are sorted on the basis of their scores.</li>
<li>Then the raw score given by the library is calculated as the sum of books that can be scanned after the signing process on the basis of number of days left.</li>
<li>The actual score(on the basis of which libraries are ordered) is then calculated by dividing the raw scores by the number of days required to sign-up the library.</li>
<li>This method is used because once the library is signed up, it isn't a liability anymore. But during the signup process, it is a liability and the libraries taking too much time should be signed up last for maximum score. You can signup multiple libraries with lesser raw scores during the time instead of signing up libraries with high signing time. The combination of scores of these multiple libraries will exceed one single big library</li>
<li>We used the formula raw_score/signup_days as comparison and scoring of libraries. You can use a different formula such as raw_score/(signup_days)^2 OR raw_score/(signup_days)^0.5 OR raw_score/log(signup_days) OR vary the power accordingly to give more or less weightage to the number of signup days.</li>
<li>Some input files will give a slightly better score if we give slightly more/less weightage to number of signup days(around power of 0.875 or 1.125).</li>
</ol>
<li>Then the new best library is stored at libord[1]. Then the scores of the books scanned from it is set to zero.</li>
<li>The process is repeated until the number of days left is zero.</li>
<li>The program is simultaneously keeping track of number of days left. When the number of days result in zero, the program stops ordering the libraries, it counts the number of libraries selected, and outputs the output file specified in the preprocessor directive.</li>
<li>The output files generated by the code are in the folder output as outa.txt ---- outf.txt </li>
<li>The program doesn't have any known bugs and performs well on the given dataset by Google.</li>
<li>The program was developed and tested on Ubuntu 19 VM on Windows 10. Processor: Intel i7-8750H.</li>
</ol>
</HTML>


% Start the Program

% Isaac Abella
% B377
clear; clc;
ExamScores = input("Enter an array of exam scores: ");

Scores = ExamScores;

%% Logical If-Statements
% Now we have to get the mean of these scores and take out scores that are
% lower than 69

if any(Scores <= 69)
    fprintf("There's %i failing score(s)\n", any(Scores <= 69));
end

%% Calculating the Letter Grade Score
ExamAverage = mean(Scores);

if ExamAverage >= 89
    ScoreGrade = 'A';
    fprintf("Your exam average of %.2f is a grade of '%c'\n", ExamAverage, ScoreGrade);
elseif ExamAverage <= 86 && ExamAverage > 79
    ScoreGrade = 'B';
    fprintf("Your exam average of %.2f is a grade of '%c'\n", ExamAverage, ScoreGrade);
elseif ExamAverage <=79 && ExamAverage > 69
    ScoreGrade = 'C';
    fprintf("Your exam average of %.2f is a grade of '%c'\n", ExamAverage, ScoreGrade);
elseif ExamAverage <= 69 && ExamAverage > 62
    ScoreGrade = 'D';
    fprintf("Your exam average of %.2f is a grade of '%c'\n", ExamAverage, ScoreGrade);
else 
    ScoreGrade = 'F';
    fprintf("Your exam average of %.2f is a grade of '%c'\n", ExamAverage, ScoreGrade);
end



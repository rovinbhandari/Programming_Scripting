# prints and returns r random values between s and t
randomValues <- function(r, s, t) 
{
    result <- sample(s:t, r)
    print(result)
    return(result)
}

# prints and returns mean of n random values between s and t
meanValue <- function(n, s, t)
{
    result <- mean(sample(s:t, n))
    print(result)
    return(result)
}

# 10 random values between -50 and 50
#randomValues(10, -50, 50)

# mean of 40 random numbers between 20 and 1000
meanValue(40, 20, 1000)
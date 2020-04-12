ChickList <- read.csv("ChickWeight.csv")

NumCol <- function(cwData, colName)
{
    return(length(unique(cwData[colName])[[colName]]))
}

# Number of chicks in the experiment
NumChicks <- NumCol(ChickList, "Chick")

# Number of diets in the experiment
NumDiets <- NumCol(ChickList, "Diet")

# Number of points-in-time in the experiment
NumTimes <- NumCol(ChickList, "Time")

# Frequency distribution by diet
FreqDiet <- function(cwData)
{
    diets <- cwData["Diet"]
    return(as.data.frame(table(diets)))
}

# Identify discrete values of time across dataset
TimeVals <- function(cwData)
{
    return(as.data.frame(unique(cwData[["Time"]])))
}

# Convert to a 3D 'matrix'
As3dData <- function(cwData)
{
    wtsd <- as.data.frame(cwData[ , -1])
    weightrix <- array(NA, c(22, NumDiets, NumChicks))
    for (i in 1:nrow(wtsd))
    {
        #print(i)
        #print(wtsd[i, "Time"] + 1)
        #print(wtsd[i, "Diet"])
        #print(wtsd[i, "Chick"])
        #print(wtsd[i, "weight"])
        #scan()
        weightrix[wtsd[i, "Time"] + 1, wtsd[i, "Diet"], wtsd[i, "Chick"]] <- wtsd[i, "weight"]
    }
    return(weightrix)
}

# Mean and max weight by diet

# Fastest weight gain by diet

# Auto-regressive model based on diet for weight-gain over time


###############
# Quick stats of data 
qStats <- function()
{
    chicks <- ChickList["Chick"]
    diets <- ChickList["Diet"]
    weights <- ChickList["weight"]
    print(as.data.frame(table(chicks)))
    print(as.data.frame(table(diets)))
    print(summary(weights))
}

# call functions
print(NumChicks)
print(NumDiets)
print(FreqDiet(ChickList))
print(TimeVals(ChickList))
weightrix <- As3dData(ChickList)
print(weightrix[3, 1, 2])
print(weightrix[1, , ])
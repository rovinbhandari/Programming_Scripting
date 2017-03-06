module ListsTestz

open NUnit.Framework
open FsCheck
open FsUnit
open Lists

[<Test>]
let ``check last element of valid list``() = 
    let res = Lists._1to10.Last [5..10]
    res |> should equal 10

[<Test>]
let ``check penultimate element of valid list``() =
    let res = Lists._1to10.Penultimate [5..10]
    res |> should equal 9
    
[<Test>]
let ``check kth element of valid list``() = 
    let res = Lists._1to10.Kth 3 [5..10]
    res |> should equal 7

[<Test>]
let ``check length of valid list``() = 
    let res = Lists._1to10.Length [5..10]
    res |> should equal 6

[<Test>]
let ``check reverse of valid list``() = 
    let res = Lists._1to10.Reverse [5..10]
    res |> should equal [10..-1..5]

[<Test>]
let ``check palindrome of valid list - success``() = 
    let res = Lists._1to10.Palindrome [1; 3; 4; 3; 1]
    res |> should equal true

[<Test>]
let ``check palindrome of valid list - failure``() = 
    let res = Lists._1to10.Palindrome [1; 3; 4; 5; 1]
    res |> should equal false 

[<Test>]
let ``check flattened valid list``() =
    let v1 = Lists._1to10.V 2
    let v2 = Lists._1to10.V 4
    let v3 = Lists._1to10.V 6
    let l1 = Lists._1to10.L [v1; v2]
    let l2 = Lists._1to10.L [v3; l1]
    let l3 = Lists._1to10.L [v3]
    let l4 = Lists._1to10.L [l1; l3]
    let res = Lists._1to10.Flatten l2
    res |> should equal [6; 2; 4]
    let res = Lists._1to10.Flatten v2
    res |> should equal [4]
    let res = Lists._1to10.Flatten l1
    res |> should equal [2; 4]
    let res = Lists._1to10.Flatten l4
    res |> should equal [2; 4; 6]

[<Test>]
let ``check compressed valid list``() =
    let res = Lists._1to10.Compress [1; 1; 2; 2; 2; 3; 1; 1; 4; 4]
    res |> should equal [1; 2; 3; 1; 4]
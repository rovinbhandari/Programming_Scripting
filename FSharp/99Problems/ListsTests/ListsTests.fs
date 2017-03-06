module ListsTestz

open NUnit.Framework
open FsCheck
open FsUnit
open Lists

[<Test>]
let ``check last element of valid list``() = 
    let res = Lists._1to10.Last [5..10]
    res |> should equal 10

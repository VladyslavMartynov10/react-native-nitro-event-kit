//
//  Date+Extension.swift
//  NitroEventKit
//
//  Created by VLAD on 15.02.2025.
//

import Foundation

extension Date {
    var unixTimestampInMilliseconds: Double {
        self.timeIntervalSince1970 * 1000
    }
    
    func formattedString(format: String) -> String {
        let formatter = DateFormatter()
        formatter.dateFormat = format
        return formatter.string(from: self)
    }
    
    func eventFormattedText(to endDate: Date) -> String {
        let formattedDate = self.formattedString(format: "EEEE, d MMM yyyy")
        let formattedStartTime = self.formattedString(format: "h:mm a")
        let formattedEndTime = endDate.formattedString(format: "h:mm a")
        
        return "\(formattedDate)\nfrom \(formattedStartTime) to \(formattedEndTime)"
    }
}

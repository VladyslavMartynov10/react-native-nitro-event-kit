//
//  UIApplication+Extension.swift
//  NitroEventKit
//
//  Created by VLAD on 15.02.2025.
//

import Foundation

import UIKit

extension UIApplication {
    var rootViewController: UIViewController? {
        guard let rootVc = connectedScenes
            .compactMap({ $0 as? UIWindowScene })
            .flatMap(\.windows)
            .first(where: { $0.isKeyWindow })?
            .rootViewController else { return nil }

        var activeController = rootVc
        
        while let presentedViewController = activeController.presentedViewController {
            activeController = presentedViewController
        }
        
        return activeController
    }
}
